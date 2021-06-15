// ZBrowse.h : main header file for the ZBROWSE application
//

#if !defined(AFX_ZBROWSE_H__6FEEB3C7_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_ZBROWSE_H__6FEEB3C7_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CZBrowseApp:
// See ZBrowse.cpp for the implementation of this class
//

class CZBrowseApp : public CWinApp
{
public:
	CZBrowseApp();

	CZBrowseView*	m_pBrowseView;
	CGridView*	   m_pGridView;


	CZBrowseDoc* GetDocFromApp ();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZBrowseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CZBrowseApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZBROWSE_H__6FEEB3C7_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
