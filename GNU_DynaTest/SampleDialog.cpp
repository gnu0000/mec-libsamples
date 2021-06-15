// SampleDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DynaTest.h"
#include "SampleDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSampleDialog dialog


CSampleDialog::CSampleDialog(CWnd* pParent /*=NULL*/)
	: CDynaDialog(CSampleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSampleDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSampleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDynaDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSampleDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSampleDialog, CDynaDialog)
	//{{AFX_MSG_MAP(CSampleDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSampleDialog message handlers

BOOL CSampleDialog::OnInitDialog() 
	{
	CDynaDialog::OnInitDialog();

	CStatic* pCtl = (CStatic*)GetDlgItem (IDC_LABEL);
	CFont* pFont = pCtl->GetFont ();

	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	}
