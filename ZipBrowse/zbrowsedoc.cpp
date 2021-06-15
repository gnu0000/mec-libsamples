// ZBrowseDoc.cpp : implementation of the CZBrowseDoc class
//

#include "stdafx.h"
#include "common.h"
#include "ZBrowseDoc.h"
#include "CntrItem.h"
#include "CSV.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZBrowseDoc

IMPLEMENT_DYNCREATE(CZBrowseDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CZBrowseDoc, CRichEditDoc)
	//{{AFX_MSG_MAP(CZBrowseDoc)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, CRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZBrowseDoc construction/destruction

CZBrowseDoc::CZBrowseDoc()
{
}

CZBrowseDoc::~CZBrowseDoc()
{
}

BOOL CZBrowseDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	return TRUE;
}

CRichEditCntrItem* CZBrowseDoc::CreateClientItem(REOBJECT* preo) const
{
	// cast away constness of this
	return new CZBrowseCntrItem(preo, (CZBrowseDoc*) this);
}



/////////////////////////////////////////////////////////////////////////////
// CZBrowseDoc serialization

void CZBrowseDoc::Serialize(CArchive& ar)
	{
	m_bRTF = FALSE;

	if (ar.IsStoring())
		{
		}
	else
		{
		}
	// TODO: set CRichEditDoc::m_bRTF = FALSE if you are serializing as text
	CRichEditDoc::Serialize(ar);
	}

/////////////////////////////////////////////////////////////////////////////
// CZBrowseDoc diagnostics

#ifdef _DEBUG
void CZBrowseDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CZBrowseDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZBrowseDoc commands

BOOL CZBrowseDoc::OnOpenDocument(LPCTSTR lpszPathName) 
	{
	char szFileName [256];

	if (m_zip.GetCurrentMode() > -1)
		m_zip.CloseArchive ();

	if (m_zip.OpenArchive (lpszPathName, 0) < 0)
		return FALSE;

	/*--- load name list ---*/
	m_index.RemoveAll ();
 	m_zip.GotoFirstFile ();
	char szLine [256];
	for (;;)
		{
		if (m_zip.GetCurrentFileInfo (szFileName, 256, NULL, 0) < 0)
			break;
		
		CZEntry* pze = new CZEntry ((LPCTSTR)szFileName);

		m_index[(LPCTSTR)szFileName] = pze;
 		if (m_zip.GotoNextFile () < 0)
			break;
		}
	/*--- load attribute list ---*/

	CZipArchive zipI;
	if ((zipI.OpenArchive ((CString)lpszPathName+"I", 0) >= 0))
		{
		if ((zipI.LocateFile ("idx") >= 0) && (zipI.OpenCurrentFile () >= 0))
			{
			while (zipI.ReadString (szLine, 256))
				{
				CCSV csv (szLine);
//				CZEntry *pze = m_index[csv.GetPart(0)];
				CZEntry *pze;
				m_index.Lookup (csv.GetPart(0), pze);
				if (pze)
					{
					pze->m_iGrp 		= csv.GetPartInt(1);
					pze->m_iQual 		= csv.GetPartInt(2);
					pze->m_ptScrollPos= CPoint(csv.GetPartInt(3), csv.GetPartInt(4));
					pze->m_ptSelPos 	= CPoint(csv.GetPartInt(5), csv.GetPartInt(6));
					for (int i=0; i<10; i++)
						pze->m_iCt[i] 	= csv.GetPartInt(7+i);
					pze->m_strComment = csv.GetPart(17);
					}
				}
 			zipI.CloseFile ();
			}
		zipI.CloseArchive();
		}

	CGridCtl* pGrid = CUtil::GetGrid();
	if (pGrid)
		pGrid->XferToGrid ();

	return TRUE;

// archive is left open
//	if (!CRichEditDoc::OnOpenDocument(lpszPathName))
//		return FALSE;
	}

static CString str;

CString& ToA(int i)
	{
	str.Format("%d,", i);
	return str;
	}


BOOL CZBrowseDoc::OnSaveDocument(LPCTSTR lpszPathName) 
	{
	if ((m_zip.OpenArchive ((CString)lpszPathName+"I", 1) < 0))
		return FALSE;

	CGridCtl* pGrid = CUtil::GetGrid();
	if (pGrid)
		pGrid->XferFromGrid ();

	CString strBuff, strKey;
	if (m_zip.OpenNewFile ("idx", NULL, Z_DEFAULT_COMPRESSION) >= 0)
		{
		CZEntry* pze;
		POSITION pos = m_index.GetStartPosition ();
		for (int iCt=0; pos; iCt++)
			{
			m_index.GetNextAssoc (pos, strKey, pze);

			strBuff.Empty();
			strBuff =  strKey + ",";
			strBuff += ToA(pze->m_iGrp); 
			strBuff += ToA(pze->m_iQual);
			strBuff += ToA(pze->m_ptScrollPos.x);
			strBuff += ToA(pze->m_ptScrollPos.y);
			strBuff += ToA(pze->m_ptSelPos.x);
			strBuff += ToA(pze->m_ptSelPos.y);

			for (int i=0;i<10; i++)
				strBuff += ToA(pze->m_iCt[i]);
			strBuff += pze->m_strComment;
			strBuff += "\n";

 			m_zip.WriteString ((LPCTSTR)strBuff);
			}
 		m_zip.CloseFile ();
		}
	m_zip.CloseArchive();

	return TRUE;

//	return CRichEditDoc::OnSaveDocument(lpszPathName);
	}




CZEntry::CZEntry (LPCTSTR pszFileName)
	{
	m_strName 	= pszFileName;
	m_strComment.Empty();
	m_iGrp 		= 0;
	m_iQual 		= 0;
	m_ptScrollPos= CPoint(0,0);
	m_ptSelPos 	= CPoint(0,0);

	for (int i=0; i<10; i++)
		m_iCt[i] = 0;
	}

