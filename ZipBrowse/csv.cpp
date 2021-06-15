// CSV.cpp: implementation of the CCSV class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CSV.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCSV::CCSV()
	{
	m_str.Empty();
	for (int i=0; i<MAXPARTS; i++)
		m_strPart[i].Empty();
	m_iPartCount = 0;
	}

CCSV::CCSV(CString s, BOOL bClean)
	{
	CCSV ();
	Split (s);
	}


CCSV::~CCSV()
	{
	}


int CCSV::Split (CString s, BOOL bClean)
	{
	int i, iStr;

	m_str = s;

	for (i=0; i < MAXPARTS; i++)
		m_strPart[i].Empty();

	BOOL bLastCharWasQuote = FALSE, bInQuotes=FALSE;
	for (i=iStr=0; i < s.GetLength(); i++)
		{
		if (!bInQuotes && s[i] == ',')
			{
			iStr++;
			bLastCharWasQuote = FALSE;
			continue;
			}
		if (s[i] != '"')
			{
			m_strPart[iStr] += s[i];
			bLastCharWasQuote = FALSE;
			continue;
			}
		if (bInQuotes)
			{
			bInQuotes = FALSE;
			bLastCharWasQuote = TRUE;
			continue;
			}
		if (bLastCharWasQuote)
			m_strPart[iStr] += s[i];
		bInQuotes = TRUE;
		bLastCharWasQuote = TRUE;
		}
	m_iPartCount = iStr+1;
	for (i=0; bClean && i < m_iPartCount; i++)
		m_strPart[i].TrimLeft(), m_strPart[i].TrimRight();
	return m_iPartCount;
	}

CString CCSV::GetPart (int iPart)
	{
	if (iPart >= m_iPartCount)
		return "";
	return m_strPart[iPart];
	}

int CCSV::GetPartInt (int iPart)
	{
	return atoi (GetPart(iPart));
	}

CString CCSV::SetPart (CString strPart, int iPart)
	{
	return m_strPart[iPart] = strPart;
	}

int CCSV::GetPartCount ()
	{
	return m_iPartCount;
	}
