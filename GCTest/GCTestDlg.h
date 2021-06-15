// GCTestDlg.h : header file
//

#if !defined(AFX_GCTESTDLG_H__2296A083_E0E4_427E_8A65_9222E0CB900C__INCLUDED_)
#define AFX_GCTESTDLG_H__2296A083_E0E4_427E_8A65_9222E0CB900C__INCLUDED_
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CGCTestDlg dialog

class CGCTestDlg : public CDialog
	{
public:
	int m_iViewedWindow;
	int m_iReturn;
	int m_iOptimize; 
	int m_iLogVal;   
	int m_iDebug; 	
	int m_iStack; 	
	int m_iPack;  	
	CString m_strSourceFile;


	CGCTestDlg(CWnd* pParent = NULL);	// standard constructor

	void SetViewedWindow (int iWindow);
	int GetViewedWindow ();
	BOOL WriteToFile (CString strFile, int iCtlID);
	int SetupAppSpecificFunctions ();

	void _Initialize	();
	void _SetOptions ();
	void _Compile	();
	int  _Run ();
	void _Terminate ();

	//{{AFX_DATA(CGCTestDlg)
	enum { IDD = IDD_GCTEST_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CGCTestDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGCTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelectSource();
	afx_msg void OnSelectStatus();
	afx_msg void OnSelectOutput();
	afx_msg void OnLoad();
	afx_msg void OnRun();
	afx_msg void OnSave();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_GCTESTDLG_H__2296A083_E0E4_427E_8A65_9222E0CB900C__INCLUDED_)
