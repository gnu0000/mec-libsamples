// MarkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "common.h"
#include "MarkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMarkDlg dialog


CMarkDlg::CMarkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMarkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMarkDlg)
	m_strWords = _T("");
	m_bWholeWord = FALSE;
	m_bUnderline = FALSE;
	m_bBold = FALSE;
	m_bCase = FALSE;
	m_bAll = FALSE;
	m_iCounterCol = 0;
	//}}AFX_DATA_INIT
}


void CMarkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMarkDlg)
	DDX_Text(pDX, IDC_WORDS, m_strWords);
	DDX_Check(pDX, IDC_WHOLEWORD, m_bWholeWord);
	DDX_Check(pDX, IDC_UNDERLINE, m_bUnderline);
	DDX_Check(pDX, IDC_BOLD, m_bBold);
	DDX_Check(pDX, IDC_CASE, m_bCase);
	DDX_Check(pDX, IDC_ALL, m_bAll);
	DDX_Text(pDX, IDC_COUNTERCOL, m_iCounterCol);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMarkDlg, CDialog)
	//{{AFX_MSG_MAP(CMarkDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMarkDlg message handlers
