// e2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "e2.h"
#include "e2Dlg.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// CE2Dlg dialog

CE2Dlg::CE2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CE2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CE2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CE2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CE2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CE2Dlg, CDialog)
	//{{AFX_MSG_MAP(CE2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALC, OnCalc)
	ON_BN_CLICKED(IDC_FILE, OnFile)
	ON_BN_CLICKED(IDC_DUMP, OnDump)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CE2Dlg message handlers

double CE2Dlg::WindowXFn (double d, BOOL bSave)
	{
	CWnd* pcWnd = AfxGetMainWnd ();
	CRect cRect;pcWnd->GetWindowRect (cRect);

	if (bSave)
		{
		int iWidth = cRect.Width();
		cRect.left = (int)d;
		cRect.right = cRect.left + iWidth;
		pcWnd->MoveWindow (cRect);
		}
	return (double)cRect.left;
	}


double CE2Dlg::MoveWindowFn (double dl, double dt, double dr, double db)
	{
	CWnd* pcWnd = AfxGetMainWnd ();
	CRect cRect ((int)dl, (int)dt, (int)dr, (int)db);
	pcWnd->MoveWindow (cRect);
	return 0.0;
	}


BOOL CE2Dlg::OnInitDialog()
	{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
		{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
			{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
			}
		}	
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_dClyde = 4.0;
	m_iRudy  = 555;
	m_expr.AddVar ("fred", 8.0);
	m_expr.AddVarRef ("clyde", &m_dClyde);
	m_expr.AddVarRef ("rudy", &m_iRudy);
	m_expr.AddFn ("sin", (MATHFN1)sin);
	
	m_expr.AddTiedVar ("WindowX", CE2Dlg::WindowXFn);
	m_expr.AddFn ("MoveWindow", (MATHFN4)MoveWindowFn);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
	}


void CE2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CE2Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CE2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CE2Dlg::OnCalc() 
	{
	CString strExpr;
	GetDlgItem (IDC_IN)->GetWindowText (strExpr);
	double dResult = m_expr.Eval ((LPCTSTR)strExpr);
	CString strResult;
	strResult.Format ("%f", dResult);
	GetDlgItem (IDC_OUT)->SetWindowText (strResult);

	CString strErr;
	LPCTSTR	psz;
	int	iIndex;
	if (m_expr.IsError (psz, iIndex))
		strErr.Format ("%s : %d", psz, iIndex);
	else
		strErr = "No Error";
	GetDlgItem (IDC_ERROR)->SetWindowText (strErr);
	}

void CE2Dlg::OnFile() 
	{
	CStdioFile cFile;

	if (!cFile.Open ("eval3.in", CFile::modeRead))
		return;

	CString strExpr;
	while (cFile.ReadString (strExpr))
		{
		GetDlgItem (IDC_IN)->SetWindowText (strExpr);
		double dResult = m_expr.Eval ((LPCTSTR)strExpr);
		CString strResult;
		strResult.Format ("%f", dResult);
		GetDlgItem (IDC_OUT)->SetWindowText (strResult);

		CString strErr;
		LPCTSTR	psz;
		int	iIndex;
		if (m_expr.IsError (psz, iIndex))
			strErr.Format ("%s : %d", psz, iIndex);
		else
			strErr = "No Error";
		GetDlgItem (IDC_ERROR)->SetWindowText (strErr);
		}
	cFile.Close ();
	}


void CE2Dlg::OnDump() 
	{
	m_expr.Dump("eval3.dmp");
	}
