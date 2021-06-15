// Util.cpp: implementation of the CUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "common.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUtil::CUtil()
	{
	}

CUtil::~CUtil()
	{
	}


CZBrowseView* CUtil::GetBrowse ()
	{
	CZBrowseApp* pApp = GetApp ();
	return pApp->m_pBrowseView;
	}

CGridCtl* CUtil::GetGrid	()
	{
	CZBrowseApp* pApp = GetApp ();
	return &(pApp->m_pGridView->m_grid);
	}

CZBrowseDoc*	CUtil::GetDoc ()
	{
	CZBrowseApp* pApp = GetApp ();
	return (CZBrowseDoc*) pApp->GetDocFromApp ();
	}

CZBrowseApp* CUtil::GetApp ()
	{
	return (CZBrowseApp*)AfxGetApp ();
	}


CGridView* CUtil::GetGridView	()
	{
	CZBrowseApp* pApp = GetApp ();
	return pApp->m_pGridView;
	}
