// DynaTest.h : main header file for the DYNATEST application
//

#if !defined(AFX_DYNATEST_H__6121D99C_F04E_11D3_91D9_FB8189031921__INCLUDED_)
#define AFX_DYNATEST_H__6121D99C_F04E_11D3_91D9_FB8189031921__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDynaTestApp:
// See DynaTest.cpp for the implementation of this class
//

class CDynaTestApp : public CWinApp
{
public:
	CDynaTestApp();

	int	  m_iMode; 

	CString  m_strFont;
	int	   m_iFontSize;

	CString  m_strBitmap;
	COLORREF m_clrTop;
	COLORREF m_clrBottom;
	COLORREF m_clrBkg;
	COLORREF m_clrFont;
	BOOL		m_bAllowResize;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynaTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDynaTestApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNATEST_H__6121D99C_F04E_11D3_91D9_FB8189031921__INCLUDED_)
