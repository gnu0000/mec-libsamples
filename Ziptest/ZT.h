// ZT.h : main header file for the ZT application
//

#if !defined(AFX_ZT_H__C9728012_59CE_4053_A6B7_7BF1F1DBBECD__INCLUDED_)
#define AFX_ZT_H__C9728012_59CE_4053_A6B7_7BF1F1DBBECD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZTApp:
// See ZT.cpp for the implementation of this class
//

class CZTApp : public CWinApp
{
public:
	CZTApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZTApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZT_H__C9728012_59CE_4053_A6B7_7BF1F1DBBECD__INCLUDED_)
