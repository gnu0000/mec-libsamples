// ZTDlg.h : header file
//

#if !defined(AFX_ZTDLG_H__D2544E02_96DB_4251_A2C3_31CB87DBE36B__INCLUDED_)
#define AFX_ZTDLG_H__D2544E02_96DB_4251_A2C3_31CB87DBE36B__INCLUDED_
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CZTDlg dialog

class CZTDlg : public CDialog
	{
public:
	CZipArchive	      m_zip;
	CSecureZipArchive m_SecureZip;
	CGZFile				m_GZ;
	CSecureGZFile		m_SecureGZ;


	CZTDlg(CWnd* pParent = NULL);	// standard constructor

	//{{AFX_DATA(CZTDlg)
	enum { IDD = IDD_ZT_DIALOG };
	CString	m_strSrcFile1;
	CString	m_strSrcFile2;
	CString	m_strSrcFile3;
	CString	m_strArcFile;
	CString	m_strPassword;
	BOOL	m_bStripPath;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CZTDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	void AddFile(LPCTSTR pszName);
	void ExtractFile();
	void ExtractGZRC4File();
	void AddGZRC4File(LPCTSTR pszName);
	void SecureAddFile(LPCTSTR pszName);
	void SecureExtractFile();
	void Rc4EncryptFile (CString strInFile, CString strOutFile);

protected:
	HICON m_hIcon;

	//{{AFX_MSG(CZTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBrowse1();
	afx_msg void OnBrowse2();
	afx_msg void OnBrowse3();
	afx_msg void OnBrowse4();
	afx_msg void OnZip();
	afx_msg void OnZip2();
	afx_msg void OnUnzip();
	afx_msg void OnUnzip2();
	afx_msg void OnSecureZip();
	afx_msg void OnSecureUnzip();
	afx_msg void OnGz();
	afx_msg void OnUngz();
	afx_msg void OnQuery1();
	afx_msg void OnQuery2();
	afx_msg void OnQuery3();
	afx_msg void OnQuery4();
	afx_msg void OnDefaults1();
	afx_msg void OnDefaults2();
	afx_msg void OnDefaults3();
	afx_msg void OnDefaults4();
	afx_msg void OnRc4();
	afx_msg void OnUnRc4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_ZTDLG_H__D2544E02_96DB_4251_A2C3_31CB87DBE36B__INCLUDED_)
