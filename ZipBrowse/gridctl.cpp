// GridCtl.cpp: implementation of the CGridCtl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "common.h"
#include "GridCtl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGridCtl::CGridCtl()
	{
	m_iMarkCol = 3;
	}

CGridCtl::~CGridCtl()
	{
	}

static int iSortOders[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void CGridCtl::OnTH_LClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed)
	{
	if (!updn)
		return;
	SortBy (col, 1+iSortOders[col]);
	iSortOders[col] = 1-iSortOders[col];
	Invalidate ();
	}


void CGridCtl::OnLClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed)
	{
	if (!updn)
		return;
	int iCol = GetCurrentCol ();
	if (iCol > 0)
		StartEdit ();
	else
		{
//		CZBrowseView* pView = CUtil::GetBrowse ();
//		pView->ChangeView (QuickGetText (col, row));
		}
	}


void CGridCtl::OnRowChange(long oldrow,long newrow)
	{
	//CZBrowseView* pView = CUtil::GetBrowse ();
	//pView->ChangeView (QuickGetText (0, newrow));

	CUtil::GetBrowse ()->ChangeView (QuickGetText (0, newrow));
	}


void CGridCtl::OnCharDown(UINT *vcKey,BOOL processed)
	{
	int iCol = GetCurrentCol ();
	if (iCol > 0)
		StartEdit ();
	}

int  CGridCtl::OnEditStart(int col, long row, CWnd **edit)
	{
	return TRUE;
	}

int CGridCtl::OnEditFinish(int col, long row,CWnd* edit,CString& string,BOOL cancelFlag)
	{
	if (cancelFlag)
		return TRUE;
		
//	CPropertyPage *pcWnd = (CPropertyPage *)GetParent();
//	pcWnd->SetModified (TRUE);
	return TRUE;
	}


void CGridCtl::RowUp ()
	{
	int iRow = GetCurrentRow ();
	int iCol = GetCurrentCol ();

	if (iRow)
		{
		SwapRow (iRow, iRow-1);
		GotoCell (iCol, iRow-1);
		}
	}

void CGridCtl::RowDown ()
	{
	int iRow = GetCurrentRow ();
	int iCol = GetCurrentCol ();

	if (iRow < GetNumberRows ()-1)
		{
		SwapRow (iRow, iRow+1);
		GotoCell (iCol, iRow+1);
		}
	}



void CGridCtl::SwapRow (int i1, int i2)
	{
	CUGCell cell1, cell2;

	for (int i=0; i < GetNumberCols (); i++)
		{
		GetCell (i, i1, &cell1);
		GetCell (i, i2, &cell2);
		SetCell (i, i1, &cell2);
		SetCell (i, i2, &cell1);
		}
	RedrawRow (i1);
	RedrawRow (i2);
	}

void CGridCtl::SetInt (int iCol, int iRow, int iVal)
	{
	CUGCell cell; 

	GetCell (iCol, iRow, &cell);

	cell.SetAlignment (UG_ALIGNRIGHT);
	cell.SetNumberDecimals (0);
	cell.SetNumber (iVal);
	SetCell (iCol, iRow, &cell);

//	CString str;
//	str.Format ("%3.3d", iVal);
//	cell.SetText (str);
	}


void CGridCtl::XferToGrid ()
	{
	CZBrowseDoc* pDoc = CUtil::GetDoc();
	CZEntry* pze;
	CString	strKey, strTmp;

	if (!pDoc)
		return;

	GetDataSource(0)->Empty();

	POSITION pos = pDoc->m_index.GetStartPosition ();
	for (int iCt=0; pos; iCt++)
		pDoc->m_index.GetNextAssoc (pos, strKey, pze);
	SetNumberRows (iCt);

	pos = pDoc->m_index.GetStartPosition ();
	for (iCt=0; pos; iCt++)
		{
		pDoc->m_index.GetNextAssoc (pos, strKey, pze);

		CUGCell cell; 
		GetCell (0, iCt, &cell);
		CZEntry** pp = (CZEntry**)cell.AllocExtraMem(sizeof (CZEntry*));
		*pp = pze;

		cell.SetText (pze->m_strName);
		SetCell (0, iCt, &cell);
		SetInt (1, iCt, pze->m_iGrp); 
		SetInt (2, iCt, pze->m_iQual);
		for (int i=0; i<10; i++)
			SetInt (3+i, iCt, pze->m_iCt[i]); 

		QuickSetText(13, iCt, pze->m_strComment);
		}

//	GotoRow(0);
//	UpdateWindow ();
//	SortBy (0, 1);
//	Invalidate ();
	}



void CGridCtl::XferFromGrid ()
	{
	CZBrowseDoc* pDoc = CUtil::GetDoc();
	if (!pDoc)
		return;

	CZEntry* pze;
	for (int i=0; i<GetNumberRows(); i++)
		{
		if (pze = pDoc->m_index[QuickGetText (0, i)])
			{
			pze->m_iGrp			  = atoi (QuickGetText (1, i));
			pze->m_iQual		  = atoi (QuickGetText (2, i));
			for (int j=0; j<10; j++)
				pze->m_iCt[j] = atoi (QuickGetText(3+j, i));

			pze->m_strComment	  = QuickGetText (13, i);
			}
		}
	}

#define COLS 14

void CGridCtl::Init()
	{
	SetSH_Width (0);
	SetTH_NumberRows (0);
	SetTH_Height(14);

	SetUniformRowHeight(1);
	SetDefRowHeight(16);

	SetVScrollMode (UG_SCROLLTRACKING);
	SetHScrollMode (UG_SCROLLTRACKING);

	SetCurrentCellMode (0x02);

	SetNumberCols (COLS);

	int iItemFont  = AddFont (_T("MS Sans Serif"), 12, FW_MEDIUM);
	int iLablFont  = AddFont (_T("MS Sans Serif"), 12, FW_BOLD);
	SetDefFont (iItemFont);
	for (int i=0; i<COLS; i++)
		QuickSetFont(i, -1, iLablFont);

	QuickSetText(0, -1, "Name");
	QuickSetText(1, -1, "Grp");
	QuickSetText(2, -1, "Q");
	QuickSetText(13, -1, "Comment");

  	// setup headings layout
	int iCWidth = 8;

	for (i=0; i<GetNumberCols (); i++)
		SetColWidth (i, iCWidth * 4 );	 // Line #

	SetColWidth (0, iCWidth * 12 );	 // Line #
	SetColWidth (13, iCWidth * 40 );	 // Line #

	LockColumns (1);
	}



void CGridCtl::NextDoc(BOOL bUp)
	{
	int iRow = GetCurrentRow() + (bUp ? -1 : 1);
	if (iRow < 0)	iRow = GetNumberRows()-1;
	if (iRow >= GetNumberRows()) iRow = 0;
	GotoCell(0, iRow);
	}

void CGridCtl::NextDoc()
	{
	NextDoc (0);
	}

void CGridCtl::PrevDoc()
	{
	NextDoc (1);
	}

static BOOL bGlobalMarkMode = FALSE;

void CGridCtl::SetCt (int iCt)
	{
	CString str;
	str.Format ("%4.4d", iCt);
	QuickSetText (m_iMarkCol, GetCurrentRow(), str);
	RedrawCell(m_iMarkCol, GetCurrentRow());
	//UpdateWindow ();

	if (bGlobalMarkMode)
		{
		int iRow = GetCurrentRow() + 1;

		if (int iState = GetKeyState (VK_SHIFT) & 0x8000)
			bGlobalMarkMode = FALSE;
		else if (iRow < GetNumberRows())
			GotoCell(0, iRow);
		else
			bGlobalMarkMode = FALSE;
		}
		
	}

void CGridCtl::SetCtHeader (CString str)
	{
	QuickSetText (m_iMarkCol, -1, str);
	RedrawCell (m_iMarkCol, -1);
	}



void CGridCtl::Global ()
	{
	bGlobalMarkMode = TRUE;

	if (GetCurrentRow())
		GotoCell(0, 0);
	else
		OnRowChange(0, 0);
	}
