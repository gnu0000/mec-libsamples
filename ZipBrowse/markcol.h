#if !defined(AFX_MARKCOL_H__47421001_F92E_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_MARKCOL_H__47421001_F92E_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MarkCol.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMarkCol dialog

class CMarkCol : public CDialog
{
// Construction
public:
	CMarkCol(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMarkCol)
	enum { IDD = IDD_MARKCOL };
	int		m_iMarkCol;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMarkCol)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMarkCol)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MARKCOL_H__47421001_F92E_11D3_91D9_E5A7CEB81F25__INCLUDED_)
