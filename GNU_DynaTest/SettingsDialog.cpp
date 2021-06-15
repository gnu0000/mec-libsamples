// SettingsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DynaTest.h"
#include "SettingsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog dialog


CSettingsDialog::CSettingsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingsDialog::IDD, pParent)
	{
	//{{AFX_DATA_INIT(CSettingsDialog)
	m_strFont      = _T("");
	m_strBitmap    = _T("");
	m_bAllowResize = FALSE;
	m_iMode = -1;
	m_iFontSize = 0;
	//}}AFX_DATA_INIT
	}


void CSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingsDialog)
	DDX_Text(pDX,  IDC_FONTNAME, 	  m_strFont);
	DDX_Text(pDX,  IDC_BMPFILE, 	  m_strBitmap);
	DDX_Check(pDX, IDC_ALLOWRESIZE, m_bAllowResize);
	DDX_Radio(pDX, IDC_USENONE, 	  m_iMode);
	DDX_Text(pDX, IDC_FONTSIZE, 	  m_iFontSize);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingsDialog, CDialog)
	//{{AFX_MSG_MAP(CSettingsDialog)
	ON_BN_CLICKED(IDC_TOPCOLOR, 			OnTopColor)
	ON_BN_CLICKED(IDC_BOTTOMCOLOR, 		OnBottomColor)
	ON_BN_CLICKED(IDC_BACKGROUNGCOLOR,  OnBackgroungColor)
	ON_BN_CLICKED(IDC_TEXTCOLOR, 			OnTextColor)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_FINDFILE, OnFindFile)
	ON_BN_CLICKED(IDC_USEBMPRESOURCE, OnUseBmpResource)
	ON_BN_CLICKED(IDC_USEBMP, OnUseBmp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog message handlers

COLORREF CSettingsDialog::GetColor(COLORREF &clr)
	{
	CColorDialog cDlg;

	cDlg.m_cc.Flags |= CC_ANYCOLOR | CC_RGBINIT | CC_FULLOPEN;
	cDlg.m_cc.rgbResult = clr;

	if (cDlg.DoModal() == IDOK)
		clr = cDlg.m_cc.rgbResult;
	return clr;
	}


void CSettingsDialog::OnTopColor() 
	{
	GetColor (m_clrTop);
	PaintBox (NULL, IDC_CLRTOP, 			m_clrTop);
	}

void CSettingsDialog::OnBottomColor() 
	{
	GetColor (m_clrBottom);
	PaintBox (NULL, IDC_CLRBOTTOM, 		m_clrBottom);
	}

void CSettingsDialog::OnBackgroungColor() 
	{
	GetColor (m_clrBkg);
	PaintBox (NULL, IDC_CLRBACKGROUND, 	m_clrBkg);
	}

void CSettingsDialog::OnTextColor() 
	{
	GetColor (m_clrFont);
	PaintBox (NULL, IDC_CLRTEXT, 			m_clrFont);
	}

void CSettingsDialog::PaintBox (CDC* pDC, int iCtlID, COLORREF clr)
	{
	CRect rect;

	pDC = pDC ? pDC : GetDC ();

	GetDlgItem(iCtlID)->GetWindowRect (rect);
	ScreenToClient (rect);
	CBrush cBrush (clr);
	CBrush* pOldBrush = (CBrush*)pDC->SelectObject (&cBrush);
	pDC->Rectangle (&rect);
	pDC->SelectObject (pOldBrush);
	}

BOOL CSettingsDialog::OnEraseBkgnd(CDC* pDC) 
	{
	BOOL bRet = CDialog::OnEraseBkgnd(pDC);

	PaintBox (pDC, IDC_CLRTOP, 			m_clrTop);
	PaintBox (pDC, IDC_CLRBOTTOM, 		m_clrBottom);
	PaintBox (pDC, IDC_CLRBACKGROUND, 	m_clrBkg);
	PaintBox (pDC, IDC_CLRTEXT, 			m_clrFont);
	return bRet;
	}

void CSettingsDialog::OnFindFile() 
	{
	PSZ pszFilter = "Bitmaps (*.bmp)|*.bmp|All Files (*.*)|*.*||";

	CFileDialog cDlg (TRUE, ".bmp", m_strBitmap, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ENABLESIZING , pszFilter);
	cDlg.m_ofn.lpstrTitle = "Select Background Bitmap";
	if (cDlg.DoModal() == IDCANCEL)
		return;
	m_strBitmap = cDlg.m_ofn.lpstrFile;
	UpdateData (FALSE);
	}


void CSettingsDialog::OnUseBmpResource() 
	{
	m_clrBkg = RGB (255,255,255);
	m_clrFont= RGB (0, 0, 0);

	UpdateData (TRUE);
	PaintBox (NULL, IDC_CLRBACKGROUND, 	m_clrBkg);
	PaintBox (NULL, IDC_CLRTEXT, 			m_clrFont);
	}

void CSettingsDialog::OnUseBmp() 
	{
	m_clrBkg  = RGB (84,84,124);
	m_clrFont = RGB (225, 255, 128);
	UpdateData (TRUE);
	PaintBox (NULL, IDC_CLRBACKGROUND, 	m_clrBkg);
	PaintBox (NULL, IDC_CLRTEXT, 			m_clrFont);
	}
