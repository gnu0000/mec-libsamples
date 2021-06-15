// ColorTreeTest.h : main header file for the COLORTREETEST application
//

#if !defined(AFX_COLORTREETEST_H__329EB715_6921_4286_A0E0_23BB3EB291E5__INCLUDED_)
#define AFX_COLORTREETEST_H__329EB715_6921_4286_A0E0_23BB3EB291E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestApp:
// See ColorTreeTest.cpp for the implementation of this class
//

class CColorTreeTestApp : public CWinApp
{
public:
	CColorTreeTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorTreeTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CColorTreeTestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORTREETEST_H__329EB715_6921_4286_A0E0_23BB3EB291E5__INCLUDED_)
