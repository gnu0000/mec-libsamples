// SamplePropPage1.cpp : implementation file
//

#include "stdafx.h"
#include "DynaTest.h"
#include "SamplePropPage1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSamplePropPage1 property page

IMPLEMENT_DYNCREATE(CSamplePropPage1, CDynaPropertyPage)

CSamplePropPage1::CSamplePropPage1() : CDynaPropertyPage(CSamplePropPage1::IDD)
{
	//{{AFX_DATA_INIT(CSamplePropPage1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSamplePropPage1::~CSamplePropPage1()
{
}

void CSamplePropPage1::DoDataExchange(CDataExchange* pDX)
{
	CDynaPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSamplePropPage1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSamplePropPage1, CDynaPropertyPage)
	//{{AFX_MSG_MAP(CSamplePropPage1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSamplePropPage1 message handlers


