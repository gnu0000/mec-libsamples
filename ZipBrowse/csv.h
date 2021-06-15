// CSV.h: interface for the CCSV class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CSV_H__6FEEB3DC_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
#define AFX_CSV_H__6FEEB3DC_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAXPARTS 20


class CCSV
	{
public:
	CString m_str;
	CString m_strPart[MAXPARTS];
	int m_iPartCount;

	CCSV();
	CCSV(CString s, BOOL bClean=TRUE);
	virtual ~CCSV();
	int Split (CString s, BOOL bClean=TRUE);
	CString GetPart (int iPart);
	int GetPartInt (int iPart);
	CString SetPart (CString strPart, int iPart);
	int GetPartCount ();
	};

#endif // !defined(AFX_CSV_H__6FEEB3DC_F6E3_11D3_91D9_E5A7CEB81F25__INCLUDED_)
