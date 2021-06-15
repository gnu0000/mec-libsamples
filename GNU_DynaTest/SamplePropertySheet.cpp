// SamplePropertySheet.cpp : implementation file
//

#include "stdafx.h"
#include "DynaTest.h"
#include "SamplePropertySheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSamplePropertySheet

IMPLEMENT_DYNAMIC(CSamplePropertySheet, CPropertySheet)


CSamplePropertySheet::CSamplePropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
	{
	AddPage(&m_Sheet1);
	AddPage(&m_Sheet2);
	}

CSamplePropertySheet::~CSamplePropertySheet()
{
}


BEGIN_MESSAGE_MAP(CSamplePropertySheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSamplePropertySheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSamplePropertySheet message handlers
