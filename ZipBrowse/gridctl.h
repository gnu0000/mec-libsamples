// GridCtl.h: interface for the CGridCtl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRIDCTL_H__6FEEB3DD_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_GRIDCTL_H__6FEEB3DD_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGridCtl : public CUGCtrl  
	{
public:
	int m_iMarkCol;

	void Init ();
	CGridCtl();
	virtual ~CGridCtl();

	void XferToGrid ();
	void XferFromGrid ();

	void OnTH_LClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed=0);
	void OnLClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed);
	void OnCharDown(UINT *vcKey,BOOL processed);
	int  OnEditStart(int col, long row, CWnd **edit);
	int  OnEditFinish(int col, long row,CWnd* edit,CString& string,BOOL cancelFlag);
	void RowUp ();
	void RowDown ();
	void SwapRow (int i1, int i2);

	void NextDoc(BOOL bUp);
	void NextDoc();
	void PrevDoc();

	void OnRowChange(long oldrow,long newrow);

	void SetInt (int iCol, int iRow, int iVal);
	void SetCt (int iCt);
	void SetCtHeader (CString str);
	void Global ();
	};

#endif // !defined(AFX_GRIDCTL_H__6FEEB3DD_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
