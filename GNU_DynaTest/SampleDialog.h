#if !defined(AFX_SAMPLEDIALOG_H__6121D9B1_F04E_11D3_91D9_FB8189031921__INCLUDED_)
#define AFX_SAMPLEDIALOG_H__6121D9B1_F04E_11D3_91D9_FB8189031921__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SampleDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSampleDialog dialog

class CSampleDialog : public CDynaDialog
{
// Construction
public:
	CSampleDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSampleDialog)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSampleDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEDIALOG_H__6121D9B1_F04E_11D3_91D9_FB8189031921__INCLUDED_)
