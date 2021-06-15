// GridView.cpp : implementation file
//

#include "stdafx.h"
#include "common.h"
#include "GridView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGridView

IMPLEMENT_DYNCREATE(CGridView, CFormView)

CGridView::CGridView()
	: CFormView(CGridView::IDD)
{
	//{{AFX_DATA_INIT(CGridView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CGridView::~CGridView()
{
}

void CGridView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGridView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGridView, CFormView)
	//{{AFX_MSG_MAP(CGridView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGridView diagnostics

#ifdef _DEBUG
void CGridView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGridView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGridView message handlers


void CGridView::OnInitialUpdate() 
	{
	CUGCell cell;

	if (m_grid.m_hWnd == 0)
		m_grid.AttachGrid (this, IDC_GRID);

	m_grid.Init();

	CFormView::OnInitialUpdate();
	}

void CGridView::OnSize(UINT nType, int cx, int cy) 
	{
	CFormView::OnSize(nType, cx, cy);

	if (!GetDlgItem(IDC_GRID) || m_grid.m_hWnd == 0)  // not created yet?
		return;
	CRect rect (0,0,cx,cy);
	GetDlgItem (IDC_GRID)->MoveWindow(rect);
	}


