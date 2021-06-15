// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "common.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_INITMENUPOPUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
	{
	CRect cRect;
	GetWindowRect (&cRect);
	int iSplitPos = cRect.Width() / 4;



	BOOL bRet = m_splitter.CreateStatic(this,1,2);
	bRet |= m_splitter.CreateView(0,0,RUNTIME_CLASS(CGridView),   CSize(iSplitPos,100), pContext);
	bRet |= m_splitter.CreateView(0,1,RUNTIME_CLASS(CZBrowseView), CSize(100,100), pContext);

	CZBrowseApp* pApp = CUtil::GetApp ();
	pApp->m_pGridView	  = (CGridView*)    m_splitter.GetPane(0,0);
	pApp->m_pBrowseView = (CZBrowseView*) m_splitter.GetPane(0,1);

// 	SetActiveView(pApp->m_pGridView); // needed ?
 	SetActiveView(pApp->m_pBrowseView);  //needed ?


//	if (!pbfo || !pbfo->pszName || !*pbfo->pszName || !stricmp (pbfo->pszName, "Unknown"))
//		PostMessage (WM_COMMAND, ID_FIRSTRUN, 0);
	return bRet;
	}

void CMainFrame::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu) 
	{
//	if (nIndex == 1)
//		{
//	 	SetActiveView(CUtil::GetGridView	()); // needed ?
//		CUtil::GetGrid()->SetFocus ();
//		CUtil::GetGrid()->SetActive();
//		}

	CFrameWnd::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);
	}
