#if !defined(AFX_SAMPLEPROPERTYSHEET_H__51A14185_F27E_11D3_91D9_88CD3617A926__INCLUDED_)
#define AFX_SAMPLEPROPERTYSHEET_H__51A14185_F27E_11D3_91D9_88CD3617A926__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SamplePropPage1.h"
#include "SamplePropPage2.h"

// SamplePropertySheet.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CSamplePropertySheet

class CSamplePropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSamplePropertySheet)

// Construction
public:
	CSamplePropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CSamplePropPage1 m_Sheet1;
	CSamplePropPage2 m_Sheet2;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSamplePropertySheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSamplePropertySheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSamplePropertySheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEPROPERTYSHEET_H__51A14185_F27E_11D3_91D9_88CD3617A926__INCLUDED_)
