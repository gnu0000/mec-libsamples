// DynaTestDoc.cpp : implementation of the CDynaTestDoc class
//

#include "stdafx.h"
#include "DynaTest.h"

#include "DynaTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynaTestDoc

IMPLEMENT_DYNCREATE(CDynaTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CDynaTestDoc, CDocument)
	//{{AFX_MSG_MAP(CDynaTestDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynaTestDoc construction/destruction

CDynaTestDoc::CDynaTestDoc()
{
}

CDynaTestDoc::~CDynaTestDoc()
{
}

BOOL CDynaTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDynaTestDoc serialization

void CDynaTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDynaTestDoc diagnostics

#ifdef _DEBUG
void CDynaTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynaTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynaTestDoc commands
