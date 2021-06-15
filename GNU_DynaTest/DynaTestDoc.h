// DynaTestDoc.h : interface of the CDynaTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNATESTDOC_H__6121D9A4_F04E_11D3_91D9_FB8189031921__INCLUDED_)
#define AFX_DYNATESTDOC_H__6121D9A4_F04E_11D3_91D9_FB8189031921__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynaTestDoc : public CDocument
{
protected: // create from serialization only
	CDynaTestDoc();
	DECLARE_DYNCREATE(CDynaTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynaTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynaTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDynaTestDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNATESTDOC_H__6121D9A4_F04E_11D3_91D9_FB8189031921__INCLUDED_)
