// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DynaTest.h"
#include "SampleDialog.h"
#include "SamplePropertySheet.h"
#include "MainFrm.h"
#include "SettingsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_SAMPLEDIALOG, OnEditSampleDialog)
	ON_COMMAND(ID_EDIT_SAMPLEPROPSHEET, OnEditSamplePropSheet)
	ON_COMMAND(ID_EDIT_SETDEFAULTS, OnEditSetDefaults)
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
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
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
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnEditSampleDialog() 
	{
	CSampleDialog	cDlg;

	CDynaTestApp* pApp = (CDynaTestApp*)AfxGetApp();

	cDlg.SetFont (pApp->m_strFont,  pApp->m_iFontSize);

	if (pApp->m_iMode == 1)
		cDlg.SetBkg (pApp->m_clrTop, pApp->m_clrBottom, pApp->m_clrFont);
	else if (pApp->m_iMode == 2)
		cDlg.SetBkg (pApp->m_strBitmap, pApp->m_clrBkg, pApp->m_clrFont);
	else if (pApp->m_iMode == 3)
		cDlg.SetBkg ((USHORT)IDB_BITMAP1, pApp->m_clrBkg, pApp->m_clrFont);

	cDlg.UseResizingControls (pApp->m_bAllowResize, IDC_MR, IDC_SR, IDC_MB, IDC_SB);

//	cDlg.m_dhBkg.m_iStripes = 128;
//	cDlg.SetFont ("Arial Bold", 8);
////	cDlg.SetBkg (RGB(255,255,255), RGB(255,255,128), RGB(0,0,0));
// 	cDlg.SetBkg (RGB(128,0,0), RGB(0,0,0), RGB(0,255,255));
////	cDlg.SetBkg ("bkg2.bmp", RGB(84,84,124), RGB(255,255,64));

	cDlg.DoModal ();
	}

void CMainFrame::OnEditSamplePropSheet() 
	{
	CSamplePropertySheet cDlg ("PropPage sample",AfxGetMainWnd(), 0);

	CDynaTestApp* pApp = (CDynaTestApp*)AfxGetApp();

   cDlg.m_Sheet1.SetFont (pApp->m_strFont,  pApp->m_iFontSize);
   cDlg.m_Sheet2.SetFont (pApp->m_strFont,  pApp->m_iFontSize);
	if (pApp->m_iMode == 1)
		{
		cDlg.m_Sheet1.SetBkg (pApp->m_clrTop, pApp->m_clrBottom, pApp->m_clrFont);
		cDlg.m_Sheet2.SetBkg (pApp->m_clrTop, pApp->m_clrBottom, pApp->m_clrFont);
		}
	else if (pApp->m_iMode == 2)
		{
		cDlg.m_Sheet1.SetBkg (pApp->m_strBitmap, pApp->m_clrBkg, pApp->m_clrFont);
		cDlg.m_Sheet2.SetBkg (pApp->m_strBitmap, pApp->m_clrBkg, pApp->m_clrFont);
		}
	else if (pApp->m_iMode == 3)
		{
		cDlg.m_Sheet1.SetBkg ((USHORT)IDB_BITMAP1, pApp->m_clrBkg, pApp->m_clrFont);
		cDlg.m_Sheet2.SetBkg ((USHORT)IDB_BITMAP1, pApp->m_clrBkg, pApp->m_clrFont);
		}
	cDlg.m_Sheet1.UseResizingControls (pApp->m_bAllowResize, IDC_MR, IDC_SR, IDC_MB, IDC_SB);
	cDlg.m_Sheet2.UseResizingControls (pApp->m_bAllowResize, IDC_MR, IDC_SR, IDC_MB, IDC_SB);


	cDlg.DoModal ();
	}

void CMainFrame::OnEditSetDefaults() 
	{
	CSettingsDialog cDlg;


	if (GetDeviceCaps (GetDC()->m_hDC, BITSPIXEL) <= 8)
		AfxMessageBox ("The background color fade and background bitmap features are only "
		               "enabled for hi-color and tru-color displays.");


	CDynaTestApp* pApp = (CDynaTestApp*)AfxGetApp();

	cDlg.m_strFont		  = pApp->m_strFont;		
	cDlg.m_iFontSize	  = pApp->m_iFontSize;	
	cDlg.m_iMode		  = pApp->m_iMode;		   
	cDlg.m_strBitmap	  = pApp->m_strBitmap;	
	cDlg.m_clrBkg		  = pApp->m_clrBkg;		
	cDlg.m_clrTop		  = pApp->m_clrTop;		
	cDlg.m_clrBottom	  = pApp->m_clrBottom;	
	cDlg.m_clrFont		  = pApp->m_clrFont;		
	cDlg.m_bAllowResize = pApp->m_bAllowResize;

	if (cDlg.DoModal () == IDOK)
		{
		pApp->m_strFont	  	=	cDlg.m_strFont		 ; 		
		pApp->m_iFontSize	  	=	cDlg.m_iFontSize	 ; 	
		pApp->m_iMode		  	=	cDlg.m_iMode		 ; 		   
		pApp->m_strBitmap	  	=	cDlg.m_strBitmap	 ; 	
		pApp->m_clrBkg		  	=	cDlg.m_clrBkg		 ; 		
		pApp->m_clrTop		  	=	cDlg.m_clrTop		 ; 		
		pApp->m_clrBottom	  	=	cDlg.m_clrBottom	 ; 	
		pApp->m_clrFont	  	=	cDlg.m_clrFont		 ; 		
		pApp->m_bAllowResize	=	cDlg.m_bAllowResize; 
		}
	}
	
