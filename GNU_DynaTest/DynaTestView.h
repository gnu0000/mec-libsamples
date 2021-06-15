// DynaTestView.h : interface of the CDynaTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNATESTVIEW_H__6121D9A6_F04E_11D3_91D9_FB8189031921__INCLUDED_)
#define AFX_DYNATESTVIEW_H__6121D9A6_F04E_11D3_91D9_FB8189031921__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynaTestView : public CDynaFormView
{
protected: // create from serialization only
	CDynaTestView();
	DECLARE_DYNCREATE(CDynaTestView)

public:
	//{{AFX_DATA(CDynaTestView)
	enum{ IDD = IDD_DYNATEST_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CDynaTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynaTestView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynaTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDynaTestView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DynaTestView.cpp
inline CDynaTestDoc* CDynaTestView::GetDocument()
   { return (CDynaTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNATESTVIEW_H__6121D9A6_F04E_11D3_91D9_FB8189031921__INCLUDED_)
