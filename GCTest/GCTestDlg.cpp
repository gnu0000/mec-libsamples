// GCTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCTest.h"
#include "GCTestDlg.h"
#include <GnuType.h>
#include "gclib.h"
#include "fn_c.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CGCTestDlg dialog

BEGIN_MESSAGE_MAP(CGCTestDlg, CDialog)
	//{{AFX_MSG_MAP(CGCTestDlg)
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SELECT_SOURCE, OnSelectSource)
	ON_BN_CLICKED(IDC_SELECT_STATUS, OnSelectStatus)
	ON_BN_CLICKED(IDC_SELECT_OUTPUT, OnSelectOutput)
	ON_BN_CLICKED(IDC_LOAD, OnLoad)
	ON_BN_CLICKED(IDC_RUN, OnRun)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CGCTestDlg::CGCTestDlg(CWnd* pParent /*=NULL*/) : CDialog(CGCTestDlg::IDD, pParent)
	{
	//{{AFX_DATA_INIT(CGCTestDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iViewedWindow = IDC_SOURCE;

	m_iReturn   = -1;
	m_iOptimize = -1;
	m_iLogVal	= -1;  
	m_iDebug		= -1; 	
	m_iStack		= -1; 	
	m_iPack		= -1;  	
	}

void CGCTestDlg::DoDataExchange(CDataExchange* pDX)
	{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGCTestDlg)
	//}}AFX_DATA_MAP
	}

/////////////////////////////////////////////////////////////////////////////
// CGCTestDlg message handlers

BOOL CGCTestDlg::OnInitDialog()
	{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	SetViewedWindow (m_iViewedWindow);

	_Initialize	();
	_SetOptions ();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
	}

HCURSOR CGCTestDlg::OnQueryDragIcon()
	{
	return (HCURSOR) m_hIcon;
	}

int CGCTestDlg::GetViewedWindow ()
	{
	return m_iViewedWindow;
	}


void CGCTestDlg::SetViewedWindow (int iWindow)
	{
	m_iViewedWindow = iWindow;

	GetDlgItem (IDC_SOURCE)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_STATUS)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_OUTPUT)->ShowWindow (SW_HIDE);
	GetDlgItem (iWindow)->ShowWindow (SW_SHOW);

	CString strMsg = (iWindow == IDC_SOURCE ? "Source" : (iWindow == IDC_STATUS ? "Status" : "Output"));
	GetDlgItem (IDC_WINDOWTYPE)->SetWindowText (strMsg + " View");
	}

void CGCTestDlg::OnSelectSource() 
	{
	SetViewedWindow (IDC_SOURCE);
	}

void CGCTestDlg::OnSelectStatus() 
	{
	SetViewedWindow (IDC_STATUS);
	}

void CGCTestDlg::OnSelectOutput() 
	{
	SetViewedWindow (IDC_OUTPUT);
	}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

CWnd* pTHIS;

HWND GetAWindow (int iWindow)
   {
   switch (iWindow)
      {
      case 1:  return pTHIS->GetDlgItem (IDC_SOURCE)->m_hWnd;  // WND_SRC  
      case 2:  return pTHIS->GetDlgItem (IDC_STATUS)->m_hWnd;  // WND_STAT 
      case 3:  return pTHIS->GetDlgItem (IDC_OUTPUT)->m_hWnd;  // WND_OUT  
      case 0: 
      default: return pTHIS->m_hWnd;                           // WND_MAIN 
      }
   }

int CGCTestDlg::SetupAppSpecificFunctions ()
   {
   pTHIS = this;
   AddFn (GetAWindow, DATATYPE_PTR, 600);
   AddFn (::MoveWindow, DATATYPE_PTR, 601);
   return 0;
   }

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


// Used by the compiler as the fn to produce status & error messages
//
int pFnPrint (PVOID pUserData, PSZ psz)
   {
   CEdit* pWnd = (CEdit*)pUserData;

   pWnd->SetSel (-1, -1);
   pWnd->ReplaceSel (psz);
   return 0;
   }


// Used by the compiler as the fn to exit if it encounters an error
//
void pFnExit (int i)
   {
   AfxEndThread (i);
   }

//	Call once at app startup
//
void CGCTestDlg::_Initialize	()
	{
	// direct compile output to mem so we can act as an interpreter
   GenSetOutputFn (_keepTag      , FTYP_WRITE_FILE_TAGS   );
   GenSetOutputFn (_keepFunction , FTYP_WRITE_FN          );
   GenSetOutputFn (_keepGlobStart, FTYP_WRITE_GLOBAL_START);
   GenSetOutputFn (_keepGlobData , FTYP_WRITE_GLOBAL_DATA );
   GenSetOutputFn (_keepGlobEnd  , FTYP_WRITE_GLOBAL_END  );

   // setup window for printf 
   WinPrintfSetup ((CEdit*) GetDlgItem (IDC_OUTPUT));
   ((CEdit*)GetDlgItem (IDC_SOURCE))->SetTabStops (12);
   ((CEdit*)GetDlgItem (IDC_STATUS))->SetTabStops (12);
   ((CEdit*)GetDlgItem (IDC_OUTPUT))->SetTabStops (12);

   // Set functions for compiler to use for printing an exit
   SetPrintFunction (pFnPrint, ((CEdit*)GetDlgItem (IDC_STATUS)));
   SetExitFunction (pFnExit);
   SetupAppSpecificFunctions ();
	}


//	log
//	debug
//
void CGCTestDlg::_SetOptions ()
	{
	// Set defaults as needed
	m_iOptimize = (m_iOptimize > -1 ? m_iOptimize: 0xFF	  	);
	m_iLogVal   = (m_iLogVal 	> -1 ? m_iLogVal 	: 0			);
	m_iDebug 	= (m_iDebug	 	> -1 ? m_iDebug  	: 0			);
	m_iStack 	= (m_iStack	 	> -1 ? m_iStack  	: 0x1000		);
	m_iPack  	= (m_iPack 	 	> -1 ? m_iPack   	: 4			);

	SetCompileOption (CO_LOGVAL, m_iLogVal);
	SetCompileOption (CO_OPTIMIZE, m_iOptimize);
	SetCompileOption (CO_STRUCTPACK, m_iPack);
	}


#define MAX_LINE_LEN 1024
#define TMPFILE "GCTST__.TMP"


void CGCTestDlg::_Compile	()
	{
	CEdit* pcEdit = (CEdit*) GetDlgItem (IDC_SOURCE);

	//	Currently, we cannot redirect the input to the compiler 
	//	so we write the contents of the edit box to a temp file.
   // and use that as the compiler input
	WriteToFile	(TMPFILE, IDC_SOURCE);
   Compile (TMPFILE, NULL);
	}


int CGCTestDlg::_Run ()
	{
   VMInit (m_iStack, m_iDebug);  // initialize the VM runtime
   InitInternalFunctions ();     // register standard internal functions
	InitCFunctions ();		      // register 'C' functions

   // LoadGXModule (szInFile); // load pre-compiled modules
   VMExecMain (0, NULL);

	m_iReturn = VMReturn ();

	VMTerm ();

	return m_iReturn;
	}

void CGCTestDlg::_Terminate ()
	{
	}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


BOOL CGCTestDlg::WriteToFile	(CString strFile, int iCtlID)
	{
	CEdit* pcEdit = (CEdit*) GetDlgItem (iCtlID);

	CStdioFile cOutFile;
	if (!cOutFile.Open (strFile, CFile::modeCreate | CFile::modeWrite))
		{
		AfxMessageBox (CString ("Unable to open temp file: ") + strFile);
		return FALSE;
		}
	char pszBuff[MAX_LINE_LEN];
	int iLines = pcEdit->GetLineCount ();
	for (int i=0; i < iLines; i++)
		{
		int iLen = pcEdit->GetLine (i, pszBuff, MAX_LINE_LEN);
		pszBuff[min (iLen, MAX_LINE_LEN -1)] = '\0';
		cOutFile.WriteString (CString (pszBuff) + "\n");
		}
	cOutFile.Close ();
	return TRUE;
	}


UINT MyThreadProc (LPVOID pParam)
	{
   CGCTestDlg* pDlg = (CGCTestDlg*)pParam;

	pDlg->_Compile	();
	pDlg->_Run ();
   return 0;
	}

void CGCTestDlg::OnRun() 
	{
	CWinThread* pThread = AfxBeginThread (MyThreadProc, this);
	}

void CGCTestDlg::OnSave() 
	{
	CString strTmp = "GC Files (*.GC)|*.gc|AllFiles (*.*)|*.*||";
	CFileDialog  cDlg (FALSE, ".GC", NULL, OFN_HIDEREADONLY | OFN_ENABLESIZING, strTmp);
	cDlg.m_ofn.lpstrTitle = "Save Source File";
	if (cDlg.DoModal() == IDCANCEL)
		return;

	WriteToFile	(cDlg.m_ofn.lpstrFile, IDC_SOURCE);
	}

void CGCTestDlg::OnLoad() 
	{
	CString strTmp = "GC Files (*.GC)|*.gc|AllFiles (*.*)|*.*||";
	CFileDialog  cDlg (TRUE, ".GC", NULL, OFN_HIDEREADONLY | OFN_ENABLESIZING, strTmp);
	cDlg.m_ofn.lpstrTitle = "Open Source File";
	if (cDlg.DoModal() == IDCANCEL)
		return;
	
	CStdioFile cInFile;
	if (!cInFile.Open (cDlg.m_ofn.lpstrFile, CFile::modeRead))
		AfxMessageBox (CString ("Unable to open input file: ") + cDlg.m_ofn.lpstrFile);

	CEdit* pcEdit = (CEdit*) GetDlgItem (IDC_SOURCE);
	pcEdit->SetWindowText ("");

	CString strBuff;
	while (cInFile.ReadString (strBuff))
		{
		pcEdit->SetSel (-1, -1);
		pcEdit->ReplaceSel (strBuff + "\r\n");
		}
	cInFile.Close ();
	}

void CGCTestDlg::OnClear() 
   {
	GetDlgItem (m_iViewedWindow)->SetWindowText ("");
   }
