// ColorTreeTestDoc.cpp : implementation of the CColorTreeTestDoc class
//

#include "stdafx.h"
#include "ColorTreeTest.h"

#include "ColorTreeTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestDoc

IMPLEMENT_DYNCREATE(CColorTreeTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorTreeTestDoc, CDocument)
	//{{AFX_MSG_MAP(CColorTreeTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestDoc construction/destruction

CColorTreeTestDoc::CColorTreeTestDoc()
{
	// TODO: add one-time construction code here

}

CColorTreeTestDoc::~CColorTreeTestDoc()
{
}

BOOL CColorTreeTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestDoc serialization

void CColorTreeTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestDoc diagnostics

#ifdef _DEBUG
void CColorTreeTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorTreeTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestDoc commands
