// ColorTreeTestView.h : interface of the CColorTreeTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORTREETESTVIEW_H__7C0E3F9A_4049_41D4_93E3_B1E3C2F5A1A6__INCLUDED_)
#define AFX_COLORTREETESTVIEW_H__7C0E3F9A_4049_41D4_93E3_B1E3C2F5A1A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CColorTreeTestView : public CColoredTreeView
{
protected: // create from serialization only
	CColorTreeTestView();
	DECLARE_DYNCREATE(CColorTreeTestView)

// Attributes
public:
	CColorTreeTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorTreeTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorTreeTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CColorTreeTestView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ColorTreeTestView.cpp
inline CColorTreeTestDoc* CColorTreeTestView::GetDocument()
   { return (CColorTreeTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORTREETESTVIEW_H__7C0E3F9A_4049_41D4_93E3_B1E3C2F5A1A6__INCLUDED_)
