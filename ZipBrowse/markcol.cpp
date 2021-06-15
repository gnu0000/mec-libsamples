// MarkCol.cpp : implementation file
//

#include "stdafx.h"
#include "common.h"
#include "MarkCol.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMarkCol dialog


CMarkCol::CMarkCol(CWnd* pParent /*=NULL*/)
	: CDialog(CMarkCol::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMarkCol)
	m_iMarkCol = 0;
	//}}AFX_DATA_INIT
}


void CMarkCol::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMarkCol)
	DDX_Text(pDX, IDC_MARKCOL, m_iMarkCol);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMarkCol, CDialog)
	//{{AFX_MSG_MAP(CMarkCol)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMarkCol message handlers
