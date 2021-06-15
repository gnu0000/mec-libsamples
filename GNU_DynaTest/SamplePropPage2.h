#if !defined(AFX_SAMPLEPROPPAGE2_H__51A14184_F27E_11D3_91D9_88CD3617A926__INCLUDED_)
#define AFX_SAMPLEPROPPAGE2_H__51A14184_F27E_11D3_91D9_88CD3617A926__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SamplePropPage2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSamplePropPage2 dialog

class CSamplePropPage2 : public CDynaPropertyPage
{
	DECLARE_DYNCREATE(CSamplePropPage2)

// Construction
public:
	CSamplePropPage2();
	~CSamplePropPage2();

// Dialog Data
	//{{AFX_DATA(CSamplePropPage2)
	enum { IDD = IDD_DYNATEST_PROPPAGE2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSamplePropPage2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSamplePropPage2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEPROPPAGE2_H__51A14184_F27E_11D3_91D9_88CD3617A926__INCLUDED_)
