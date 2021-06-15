// GCTest.h : main header file for the GCTEST application
//

#if !defined(AFX_GCTEST_H__9DF69947_CD27_47E0_8E01_5729B7E3138F__INCLUDED_)
#define AFX_GCTEST_H__9DF69947_CD27_47E0_8E01_5729B7E3138F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGCTestApp:
// See GCTest.cpp for the implementation of this class
//

class CGCTestApp : public CWinApp
{
public:
	CGCTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGCTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGCTestApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GCTEST_H__9DF69947_CD27_47E0_8E01_5729B7E3138F__INCLUDED_)
