// CntrItem.cpp : implementation of the CZBrowseCntrItem class
//

#include "stdafx.h"
#include "common.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZBrowseCntrItem implementation

IMPLEMENT_SERIAL(CZBrowseCntrItem, CRichEditCntrItem, 0)

CZBrowseCntrItem::CZBrowseCntrItem(REOBJECT* preo, CZBrowseDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
}

CZBrowseCntrItem::~CZBrowseCntrItem()
{
}

/////////////////////////////////////////////////////////////////////////////
// CZBrowseCntrItem diagnostics

#ifdef _DEBUG
void CZBrowseCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CZBrowseCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
