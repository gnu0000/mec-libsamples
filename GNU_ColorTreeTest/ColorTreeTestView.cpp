// ColorTreeTestView.cpp : implementation of the CColorTreeTestView class
//

#include "stdafx.h"
#include "ColorTreeTest.h"

#include "ColorTreeTestDoc.h"
#include "ColorTreeTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestView

IMPLEMENT_DYNCREATE(CColorTreeTestView, CColoredTreeView)

BEGIN_MESSAGE_MAP(CColorTreeTestView, CColoredTreeView)
	//{{AFX_MSG_MAP(CColorTreeTestView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestView construction/destruction

CColorTreeTestView::CColorTreeTestView()
{
	// TODO: add construction code here

}

CColorTreeTestView::~CColorTreeTestView()
{
}

BOOL CColorTreeTestView::PreCreateWindow(CREATESTRUCT& cs)
	{
	cs.style |= TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_NOTOOLTIPS;
	return CColoredTreeView::PreCreateWindow(cs);
	}

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestView drawing

void CColorTreeTestView::OnDraw(CDC* pDC)
{
	CColorTreeTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here



//	CRect crClient;
//	int iMin, iMax;
//   GetClientRect(crClient);
//	GetScrollRange (SB_VERT, &iMin, &iMax);
//	iMin = iMax = 0;
//	int iYInc = GetTreeCtrl().GetItemHeight();
//	return CSize (crClient.Width(), crClient.Height()+(iMax-iMin)*iYInc);

}

void CColorTreeTestView::OnInitialUpdate()
	{
	CColoredTreeView::OnInitialUpdate();

	//SetBkg  (COLORREF clrTop, COLORREF clrBottom=-1, COLORREF clrText=-1);
	//SetBkg  (LPCTSTR lpctBitmap, COLORREF clrText=-1);
	//SetBkg  (USHORT iBitmapID, COLORREF clrText=-1);

	SetBkg  (RGB(0,255,255), RGB(255,0,0), RGB(20,10,0));
//	SetBkg  ((USHORT)IDB_BITMAP1);



	CTreeCtrl &cTree = GetTreeCtrl();

	HTREEITEM h0;
	CString str;
	for (int i=0; i<16; i++)
		{
		str.Format ("This is a long runon sentence about nothing important at all (at least I think not). This is Element number %d", i);
		h0 = cTree.InsertItem (str, 0, 0);

		for (int j=0; j<16; j++)
			{
			str.Format ("Element %d.%d", i, j);
			cTree.InsertItem (str, 0, 0, h0);
			}
		}
	}

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestView diagnostics

#ifdef _DEBUG
void CColorTreeTestView::AssertValid() const
{
	CColoredTreeView::AssertValid();
}

void CColorTreeTestView::Dump(CDumpContext& dc) const
{
	CColoredTreeView::Dump(dc);
}

CColorTreeTestDoc* CColorTreeTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorTreeTestDoc)));
	return (CColorTreeTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorTreeTestView message handlers

void CColorTreeTestView::OnPaint() 
	{
	/*--- debug code ---*/
	CTreeCtrl &cTree = GetTreeCtrl();
	int iMin, iMax;
	cTree.GetScrollRange (SB_VERT, &iMin, &iMax);
	CString str;
	str.Format ("[%d:%d]", iMin, iMax);
	CWnd* pWnd = AfxGetMainWnd ();
	pWnd->SetWindowText (str);
	SetWindowText (str);




//	CPaintDC dc(this); // device context for painting
//	
//	// TODO: Add your message handler code here
//	
	CColoredTreeView::OnPaint(); // for painting messages
}
