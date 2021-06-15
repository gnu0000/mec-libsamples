// SamplePropPage2.cpp : implementation file
//

#include "stdafx.h"
#include "DynaTest.h"
#include "SamplePropPage2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSamplePropPage2 property page

IMPLEMENT_DYNCREATE(CSamplePropPage2, CDynaPropertyPage)

CSamplePropPage2::CSamplePropPage2() : CDynaPropertyPage(CSamplePropPage2::IDD)
{
	//{{AFX_DATA_INIT(CSamplePropPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSamplePropPage2::~CSamplePropPage2()
{
}

void CSamplePropPage2::DoDataExchange(CDataExchange* pDX)
{
	CDynaPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSamplePropPage2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSamplePropPage2, CDynaPropertyPage)
	//{{AFX_MSG_MAP(CSamplePropPage2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSamplePropPage2 message handlers
