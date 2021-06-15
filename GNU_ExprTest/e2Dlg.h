// e2Dlg.h : header file
//
#if !defined(AFX_E2DLG_H__C6960166_FDAF_11D3_91D9_9E8D992DA026__INCLUDED_)
#define AFX_E2DLG_H__C6960166_FDAF_11D3_91D9_9E8D992DA026__INCLUDED_
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CE2Dlg dialog

class CE2Dlg : public CDialog
	{
public:
	CExpr m_expr;

	CE2Dlg(CWnd* pParent = NULL);	// standard constructor

	static double WindowXFn (double d, BOOL bSave);
	static double MoveWindowFn (double dl, double dt, double dr, double db);

	//{{AFX_DATA(CE2Dlg)
	enum { IDD = IDD_E2_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CE2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	HICON  m_hIcon;
	double m_dClyde;
	int	 m_iRudy;

	//{{AFX_MSG(CE2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCalc();
	afx_msg void OnFile();
	afx_msg void OnDump();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_E2DLG_H__C6960166_FDAF_11D3_91D9_9E8D992DA026__INCLUDED_)
