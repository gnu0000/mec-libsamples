// Util.h: interface for the CUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTIL_H__6FEEB3DB_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_UTIL_H__6FEEB3DB_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "ZBrowseDoc.h"
//#include "ZBrowseView.h"
//#include "GridView.h"

class CUtil  
	{
public:
	CUtil();
	virtual ~CUtil();

	static CZBrowseView* GetBrowse ();
	static CGridCtl* GetGrid ();
	static CZBrowseDoc* GetDoc ();
	static CZBrowseApp* GetApp ();

	static CGridView* GetGridView	();

	};


#endif // !defined(AFX_UTIL_H__6FEEB3DB_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
