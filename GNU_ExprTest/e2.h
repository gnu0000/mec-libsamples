// e2.h : main header file for the E2 application
//

#if !defined(AFX_E2_H__C6960164_FDAF_11D3_91D9_9E8D992DA026__INCLUDED_)
#define AFX_E2_H__C6960164_FDAF_11D3_91D9_9E8D992DA026__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CE2App:
// See e2.cpp for the implementation of this class
//

class CE2App : public CWinApp
{
public:
	CE2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CE2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CE2App)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_E2_H__C6960164_FDAF_11D3_91D9_9E8D992DA026__INCLUDED_)
