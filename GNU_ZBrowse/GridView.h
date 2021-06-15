#if !defined(AFX_GRIDVIEW_H__6FEEB3DA_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_GRIDVIEW_H__6FEEB3DA_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GridView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGridView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CGridView : public CFormView
{
protected:
	CGridView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CGridView)

// Form Data
public:
	//{{AFX_DATA(CGridView)
	enum { IDD = IDD_GRIDVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CGridCtl m_grid;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGridView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CGridView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CGridView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRIDVIEW_H__6FEEB3DA_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
