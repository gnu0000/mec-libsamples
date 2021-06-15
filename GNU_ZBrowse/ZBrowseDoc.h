// ZBrowseDoc.h : interface of the CZBrowseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZBROWSEDOC_H__6FEEB3CD_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_ZBROWSEDOC_H__6FEEB3CD_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CZEntry
	{
	public:
	CString m_strName;
	int	  m_iGrp;
	int	  m_iQual;
	int	  m_iCt[10];
	CString m_strComment;
	CPoint  m_ptScrollPos;
	CPoint  m_ptSelPos;

	CZEntry (LPCTSTR pszFileName);
	};

typedef CMap<CString,LPCTSTR,CZEntry*,CZEntry*&> CZEntryMap;


class CZBrowseDoc : public CRichEditDoc
{
protected: // create from serialization only
	CZBrowseDoc();
	DECLARE_DYNCREATE(CZBrowseDoc)

// Attributes
public:
	CZEntryMap  m_index;
	CZipArchive	m_zip;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZBrowseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implementation
public:
	virtual ~CZBrowseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZBrowseDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZBROWSEDOC_H__6FEEB3CD_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
