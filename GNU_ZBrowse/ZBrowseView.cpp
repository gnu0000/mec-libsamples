// ZBrowseView.cpp : implementation of the CZBrowseView class
//

#include "stdafx.h"
#include "common.h"
#include "CntrItem.h"
#include "gotodlg.h"
#include "markdlg.h"
#include "csv.h"
//#include "MarkCol.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MYTIMER 765
#define DELAY   250

/////////////////////////////////////////////////////////////////////////////
// CZBrowseView

IMPLEMENT_DYNCREATE(CZBrowseView, CRichEditView)

BEGIN_MESSAGE_MAP(CZBrowseView, CRichEditView)
	//{{AFX_MSG_MAP(CZBrowseView)
	ON_WM_DESTROY()
	ON_COMMAND(ID_EDIT_GOTOLINE, OnEditGoToLine)
	ON_COMMAND(ID_EDIT_FONT, OnEditFont)
	ON_COMMAND(ID_EDIT_FONTUP, OnEditFontUp)
	ON_COMMAND(ID_EDIT_FONTDOWN, OnEditFontDown)
	ON_WM_TIMER()
	ON_COMMAND(ID_EDIT_MARK, OnEditMark)
	ON_COMMAND(ID_EDIT_NEXTDOC, OnEditNextDoc)
	ON_COMMAND(ID_EDIT_PREVDOC, OnEditPrevDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZBrowseView construction/destruction

CZBrowseView::CZBrowseView()
{
}

CZBrowseView::~CZBrowseView()
{
}

BOOL CZBrowseView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CRichEditView::PreCreateWindow(cs);
}


void CZBrowseView::OnInitialUpdate()
	{
	m_strCurrFile.Empty();
	CRichEditView::OnInitialUpdate();

	CRichEditCtrl &ctrl = GetRichEditCtrl();
	ctrl.SetReadOnly (TRUE);

	SetMargins(CRect(720, 720, 720, 720));

	CHARFORMAT cf;

	cf.cbSize			 = sizeof (CHARFORMAT); 
	cf.dwMask			 = CFM_BOLD|CFM_CHARSET|CFM_FACE|CFM_SIZE; 
//	cf.dwEffects		 =	; 
	cf.yHeight			 = 240; 
//	cf.yOffset			 =	; 
//	cf.crTextColor		 =	; 
	cf.bCharSet			 = DEFAULT_CHARSET; 
	cf.bPitchAndFamily = FF_DONTCARE; 
	strcpy (cf.szFaceName, "Arial");
//	strcpy (cf.szFaceName, "Ms Sans Serif");

	ctrl.SetDefaultCharFormat(cf);
	}

void CZBrowseView::OnDestroy()
{
   CRichEditView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// CZBrowseView diagnostics

#ifdef _DEBUG
void CZBrowseView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CZBrowseView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CZBrowseDoc* CZBrowseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZBrowseDoc)));
	return (CZBrowseDoc*)m_pDocument;
}
#endif //_DEBUG




static DWORD CALLBACK MyStreamInCallback(DWORD dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb)
	{
	CZipArchive* pZip = (CZipArchive*)dwCookie;

 	*pcb = pZip->Read (pbBuff, cb);
	return 0;
	}

void CZBrowseView::ChangeView(CString strName)
	{
	CZBrowseDoc* pDoc = CUtil::GetDoc();
	if (!pDoc)
		return;

	pDoc->m_bRTF = FALSE;

	if (pDoc->m_zip.LocateFile (strName) < 0)
		return;
	if (pDoc->m_zip.OpenCurrentFile () < 0)
		return;

	CRichEditCtrl &ctrl = GetRichEditCtrl( );
	CZEntry* pze;


	if (!m_strCurrFile.IsEmpty())
		{
		if(pze = pDoc->m_index[m_strCurrFile])
			pze->m_ptScrollPos = CPoint (0, ctrl.GetFirstVisibleLine());
		}

	EDITSTREAM es;
	es.pfnCallback = MyStreamInCallback; 
   es.dwCookie = (DWORD) &pDoc->m_zip;   
	ctrl.StreamIn(SF_TEXT, es);

	m_strCurrFile = strName;
	if (!m_strCurrFile.IsEmpty())
		{
		if (pze = pDoc->m_index[m_strCurrFile])
			{
			m_iYPos  = pze->m_ptScrollPos.y;
			m_iTries	= 0;
			SetTimer (MYTIMER, DELAY, NULL);
			}
		}
 	pDoc->m_zip.CloseFile ();
	Invalidate ();
	}

/////////////////////////////////////////////////////////////////////////////
// CZBrowseView message handlers



void CZBrowseView::OnEditGoToLine() 
	{
	CGotoDlg cDlg;

	CRichEditCtrl &ctrl = GetRichEditCtrl();
	int iCurrLine = ctrl.GetFirstVisibleLine();
	cDlg.m_iLine = iCurrLine;
	if (cDlg.DoModal () == IDOK)
		ctrl.LineScroll (cDlg.m_iLine - iCurrLine);
	}

void CZBrowseView::OnEditFont() 
	{
//	CFontDialog cDlg;
//
//	CRichEditCtrl &ctrl = GetRichEditCtrl();
//
//	CHARFORMAT cf;
//	ctrl.GetDefaultCharFormat (&cf);
//
//	cDlg.m_cf.Flags |= CF_INITTOLOGFONTSTRUCT ;
//
//
//  UINT     cf.cbSize;   
//  DWORD    cf.dwMask;   
//  DWORD    cf.dwEffects;   
//  LONG     cf.yHeight; 
//  LONG     cf.yOffset;   
//  COLORREF cf.crTextColor;   
//  BYTE     cf.bCharSet; 
//  BYTE     cf.bPitchAndFamily;   
//  TCHAR    cf.szFaceName[LF_FACESIZE]; 
//
//
//---logfont---
//  LONG 	cDlg.m_cf.lpLogFont->lfHeight							=
//  LONG 	cDlg.m_cf.lpLogFont->lfWidth							=
//  LONG 	cDlg.m_cf.lpLogFont->lfEscapement					=
//  LONG 	cDlg.m_cf.lpLogFont->lfOrientation					=
//  LONG 	cDlg.m_cf.lpLogFont->lfWeight							=
//  BYTE 	cDlg.m_cf.lpLogFont->lfItalic   						=
//  BYTE 	cDlg.m_cf.lpLogFont->lfUnderline   					=
//  BYTE 	cDlg.m_cf.lpLogFont->lfStrikeOut 					=
//  BYTE 	cDlg.m_cf.lpLogFont->lfCharSet   					=
//  BYTE 	cDlg.m_cf.lpLogFont->lfOutPrecision   				=
//  BYTE 	cDlg.m_cf.lpLogFont->lfClipPrecision 				=
//  BYTE 	cDlg.m_cf.lpLogFont->lfQuality						=
//  BYTE 	cDlg.m_cf.lpLogFont->lfPitchAndFamily				=
//  TCHAR 	cDlg.m_cf.lpLogFont->lfFaceName[LF_FACESIZE]; 
//----------

//	if (cDlg.DoModal() == IDOK)
//		{
//		}
	}

void CZBrowseView::OnEditFontUp() 
	{
// TODO: Add your command handler code here

	CRichEditCtrl &ctrl = GetRichEditCtrl();


	CHARFORMAT cf;
	ctrl.GetDefaultCharFormat (cf);
	cf.dwMask = CFM_SIZE;
	cf.yHeight += 20;
	ctrl.SetDefaultCharFormat (cf);

	ctrl.SetSel(0,-1);
	ctrl.SetSelectionCharFormat(cf);
	ctrl.SetSel(0,0);

	Invalidate();
	}

void CZBrowseView::OnEditFontDown() 
	{
	CRichEditCtrl &ctrl = GetRichEditCtrl();

	CHARFORMAT cf;
	ctrl.GetDefaultCharFormat (cf);
	cf.dwMask = CFM_SIZE;
	cf.yHeight -= 20;
	ctrl.SetDefaultCharFormat (cf);

	ctrl.SetSel(0,-1);
	ctrl.SetSelectionCharFormat(cf);
	ctrl.SetSel(0,0);

	Invalidate();
	}

void CZBrowseView::OnTimer(UINT nIDEvent) 
	{
	if (nIDEvent != MYTIMER)
		{
		CRichEditView::OnTimer(MYTIMER);
		return;
		}
	m_iTries++;
	CRichEditCtrl &ctrl = GetRichEditCtrl();

	if (ctrl.GetLineCount() >= m_iYPos || m_iTries > 12)
		{
		int iCurrLine = ctrl.GetFirstVisibleLine();
		ctrl.LineScroll (m_iYPos - iCurrLine);
		KillTimer (MYTIMER);
		MarkText();
		}
	}

static BOOL bBold		  = TRUE ;
static BOOL	bUnderline = FALSE;
static BOOL	bWholeWord = TRUE ;
static BOOL	bCase		  = FALSE;
static CString strWords;

void CZBrowseView::OnEditMark() 
	{
	CMarkDlg cDlg;

	cDlg.m_bBold		=	bBold		 ;
	cDlg.m_bUnderline =	bUnderline;
	cDlg.m_bWholeWord =	bWholeWord;
	cDlg.m_bCase      =	bCase		 ;
	cDlg.m_bAll			=	FALSE;
	cDlg.m_strWords	=	strWords  ;
	cDlg.m_iCounterCol	= CUtil::GetGrid()->m_iMarkCol;

	if (cDlg.DoModal() != IDOK)
		return;

	bBold		  = cDlg.m_bBold		;
	bUnderline = cDlg.m_bUnderline;
	bWholeWord = cDlg.m_bWholeWord;
	bCase		  = cDlg.m_bCase     ;
	strWords	  = cDlg.m_strWords	;

	CUtil::GetGrid()->m_iMarkCol = cDlg.m_iCounterCol;
		CUtil::GetGrid()->SetCtHeader (strWords);

	if (cDlg.m_bAll)
		CUtil::GetGrid()->Global ();
	else
		MarkText();
	}
	
void CZBrowseView::MarkText() 
	{
	if (strWords.IsEmpty())
		return;

	CCSV csv(strWords);

	CRichEditCtrl &ctrl = GetRichEditCtrl();

	CHARFORMAT cf;
	ctrl.GetDefaultCharFormat (cf);
	cf.dwMask 	 = (bUnderline ? CFM_UNDERLINE : 0) | (bBold ? CFM_BOLD : 0);
	cf.dwEffects = (bUnderline ? CFE_UNDERLINE : 0) | (bBold ? CFE_BOLD : 0);;

	int iCurrLine = ctrl.GetFirstVisibleLine();

	FINDTEXTEX ft;
	int j=0;
	for (int i=0; i< csv.GetPartCount(); i++)
		{
		CString strMatch = csv.GetPart(i);
		ft.chrg.cpMin = 0;
		for (;;)
			{
			ft.chrg.cpMax = -1;
			ft.lpstrText = (PSZ)(LPCTSTR) strMatch;
			if (ctrl.FindText((bWholeWord?FR_WHOLEWORD:0)|(bCase?FR_MATCHCASE:0), &ft) == -1)
				break;
	   	ctrl.SetSel(ft.chrgText);
			ctrl.SetSelectionCharFormat(cf);
			ft.chrg.cpMin = ft.chrgText.cpMax;
			j++;
			}
		}
	ctrl.LineScroll (iCurrLine - ctrl.GetFirstVisibleLine());

	CUtil::GetGrid()->SetCt(j);
	}

void CZBrowseView::OnEditNextDoc() 
	{
	CUtil::GetGrid()->NextDoc (0);
	}

void CZBrowseView::OnEditPrevDoc() 
	{
	CUtil::GetGrid()->NextDoc (1);
	}

//void CZBrowseView::OnEditGlobalMark() 
//	{
//	CUtil::GetGrid()->Global ();
//	}

//void CZBrowseView::OnEditMarkCol() 
//	{
//	CMarkCol cDlg;
//
//	cDlg.m_iMarkCol = CUtil::GetGrid()->m_iMarkCol;
//	
//	if (cDlg.DoModal() == IDOK)
//		CUtil::GetGrid()->m_iMarkCol = cDlg.m_iMarkCol;
//	}
