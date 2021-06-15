#if !defined(AFX_SETTINGSDIALOG_H__73881DE3_F414_11D3_91D9_88CD3617A926__INCLUDED_)
#define AFX_SETTINGSDIALOG_H__73881DE3_F414_11D3_91D9_88CD3617A926__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog dialog

class CSettingsDialog : public CDialog
{
// Construction
public:
	CSettingsDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettingsDialog)
	enum { IDD = IDD_SETUPDLG };
	CString	m_strFont		 ;
	CString	m_strBitmap	 	 ;
	COLORREF m_clrBkg		 	 ;
	COLORREF m_clrTop		 	 ;
	COLORREF m_clrBottom	 	 ;
	COLORREF m_clrFont		 ;
	BOOL     m_bAllowResize	 ;
	int		m_iMode;
	int		m_iFontSize;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	COLORREF CSettingsDialog::GetColor(COLORREF &clr);
	void PaintBox (CDC* pDC, int iCtlID, COLORREF clr);

	// Generated message map functions
	//{{AFX_MSG(CSettingsDialog)
	afx_msg void OnTopColor();
	afx_msg void OnBottomColor();
	afx_msg void OnBackgroungColor();
	afx_msg void OnTextColor();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnFindFile();
	afx_msg void OnUseBmpResource();
	afx_msg void OnUseBmp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGSDIALOG_H__73881DE3_F414_11D3_91D9_88CD3617A926__INCLUDED_)
