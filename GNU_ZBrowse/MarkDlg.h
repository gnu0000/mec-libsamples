#if !defined(AFX_MARKDLG_H__6FEEB3DF_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_MARKDLG_H__6FEEB3DF_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MarkDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMarkDlg dialog

class CMarkDlg : public CDialog
{
// Construction
public:
	CMarkDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMarkDlg)
	enum { IDD = IDD_MARK };
	CString	m_strWords;
	BOOL	m_bWholeWord;
	BOOL	m_bUnderline;
	BOOL	m_bBold;
	BOOL	m_bCase;
	BOOL	m_bAll;
	int		m_iCounterCol;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMarkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMarkDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MARKDLG_H__6FEEB3DF_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
