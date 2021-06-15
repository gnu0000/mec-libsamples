// ZBrowseView.h : interface of the CZBrowseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZBROWSEVIEW_H__6FEEB3CF_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_ZBROWSEVIEW_H__6FEEB3CF_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CZBrowseCntrItem;

class CZBrowseView : public CRichEditView
{
protected: // create from serialization only
	CZBrowseView();
	DECLARE_DYNCREATE(CZBrowseView)

// Attributes
public:
	CString m_strCurrFile;
	int m_iYPos;
	int m_iTries;

	CZBrowseDoc* GetDocument();
	void ChangeView (CString strName);

// Operations
public:
	void MarkText();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZBrowseView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CZBrowseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZBrowseView)
	afx_msg void OnDestroy();
	afx_msg void OnEditGoToLine();
	afx_msg void OnEditFont();
	afx_msg void OnEditFontUp();
	afx_msg void OnEditFontDown();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnEditMark();
	afx_msg void OnEditNextDoc();
	afx_msg void OnEditPrevDoc();
	afx_msg void OnEditGlobalMark();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ZBrowseView.cpp
inline CZBrowseDoc* CZBrowseView::GetDocument()
   { return (CZBrowseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZBROWSEVIEW_H__6FEEB3CF_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
