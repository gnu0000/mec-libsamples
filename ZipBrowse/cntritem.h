// CntrItem.h : interface of the CZBrowseCntrItem class
//

#if !defined(AFX_CNTRITEM_H__6FEEB3D2_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_CNTRITEM_H__6FEEB3D2_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CZBrowseDoc;
class CZBrowseView;

class CZBrowseCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CZBrowseCntrItem)

// Constructors
public:
	CZBrowseCntrItem(REOBJECT* preo = NULL, CZBrowseDoc* pContainer = NULL);

// Attributes
public:
	CZBrowseDoc* GetDocument()
		{ return (CZBrowseDoc*)CRichEditCntrItem::GetDocument(); }
	CZBrowseView* GetActiveView()
		{ return (CZBrowseView*)CRichEditCntrItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZBrowseCntrItem)
	public:
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	~CZBrowseCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__6FEEB3D2_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
