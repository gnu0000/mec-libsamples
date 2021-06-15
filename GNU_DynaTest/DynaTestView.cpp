// DynaTestView.cpp : implementation of the CDynaTestView class
//

#include "stdafx.h"
#include "DynaTest.h"
#include "DynaTestDoc.h"
#include "DynaTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynaTestView

IMPLEMENT_DYNCREATE(CDynaTestView, CDynaFormView)

BEGIN_MESSAGE_MAP(CDynaTestView, CDynaFormView)
	//{{AFX_MSG_MAP(CDynaTestView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynaTestView construction/destruction

CDynaTestView::CDynaTestView(): CDynaFormView(CDynaTestView::IDD)
	{
//	CDynaTestApp* pApp = (CDynaTestApp*)AfxGetApp();
//
//	SetFont (pApp->m_strFont,  pApp->m_iFontSize);
//	if (pApp->m_iMode == 1)
//		SetBkg (pApp->m_clrTop, pApp->m_clrBottom, pApp->m_clrFont);
//	else if (pApp->m_iMode == 2)
//		SetBkg (pApp->m_strBitmap, pApp->m_clrBkg, pApp->m_clrFont);
//	UseResizingControls (pApp->m_bAllowResize);
	}

CDynaTestView::~CDynaTestView()
{
}

void CDynaTestView::DoDataExchange(CDataExchange* pDX)
{
	CDynaFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDynaTestView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CDynaTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CDynaFormView::PreCreateWindow(cs);
}

void CDynaTestView::OnInitialUpdate()
	{
	CDynaFormView::OnInitialUpdate();

	CDynaTestApp* pApp = (CDynaTestApp*)AfxGetApp();

	SetFont (pApp->m_strFont,  pApp->m_iFontSize);
	if (pApp->m_iMode == 1)
		SetBkg (pApp->m_clrTop, pApp->m_clrBottom, pApp->m_clrFont);
	else if (pApp->m_iMode == 2)
		SetBkg (pApp->m_strBitmap, pApp->m_clrBkg, pApp->m_clrFont);
	else if (pApp->m_iMode == 3)
		SetBkg ((USHORT)IDB_BITMAP1, pApp->m_clrBkg, pApp->m_clrFont);
	UseResizingControls (pApp->m_bAllowResize, IDC_MR, IDC_SR, IDC_MB, IDC_SB);

	ResizeParentToFit();
	}

/////////////////////////////////////////////////////////////////////////////
// CDynaTestView diagnostics

#ifdef _DEBUG
void CDynaTestView::AssertValid() const
{
	CDynaFormView::AssertValid();
}

void CDynaTestView::Dump(CDumpContext& dc) const
{
	CDynaFormView::Dump(dc);
}

CDynaTestDoc* CDynaTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynaTestDoc)));
	return (CDynaTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynaTestView message handlers
