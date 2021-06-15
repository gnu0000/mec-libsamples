// ZBrowse.cpp : Defines the class behaviors for the application.
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
// CZBrowseApp

BEGIN_MESSAGE_MAP(CZBrowseApp, CWinApp)
	//{{AFX_MSG_MAP(CZBrowseApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZBrowseApp construction

CZBrowseApp::CZBrowseApp()
	{
	m_pBrowseView = NULL;
	m_pGridView   = NULL;
	}

/////////////////////////////////////////////////////////////////////////////
// The one and only CZBrowseApp object

CZBrowseApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CZBrowseApp initialization

BOOL CZBrowseApp::InitInstance()
{
	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register document templates

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CZBrowseDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CZBrowseView));
	pDocTemplate->SetContainerInfo(IDR_CNTR_INPLACE);
	AddDocTemplate(pDocTemplate);

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CZBrowseApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CZBrowseApp message handlers


//DEL CDocument* CZBrowseApp::OpenDocumentFile(LPCTSTR lpszFileName) 
//DEL 	{
//DEL 	//	return CWinApp::OpenDocumentFile(lpszFileName);
//DEL 
//DEL 	CGridView* pGrid = CUtil::GetGrid ();
//DEL 	if (pGrid)
//DEL 		pGrid->OpenFile (lpszFileName);
//DEL 
//DEL 
//DEL 	}


CZBrowseDoc* CZBrowseApp::GetDocFromApp ()
	{
	POSITION pos = GetFirstDocTemplatePosition ();
	CDocTemplate *pcDT = GetNextDocTemplate (pos);
	pos = pcDT->GetFirstDocPosition ();

//	if (!pos) // if we get a file open on cmd line, there is no doc yet.
//		{
//		if (!OnCmdMsg(ID_FILE_NEW, 0, NULL, NULL))
//			OnFileNew();
//		pos = pcDT->GetFirstDocPosition ();
//		}
	return (CZBrowseDoc*)pcDT->GetNextDoc (pos);
	}
