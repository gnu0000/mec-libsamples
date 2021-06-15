// ZTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZT.h"
#include "ZTDlg.h"
#include "InfoDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZTDlg dialog

BEGIN_MESSAGE_MAP(CZTDlg, CDialog)
	//{{AFX_MSG_MAP(CZTDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWSE1, OnBrowse1)
	ON_BN_CLICKED(IDC_BROWSE2, OnBrowse2)
	ON_BN_CLICKED(IDC_BROWSE3, OnBrowse3)
	ON_BN_CLICKED(IDC_BROWSE4, OnBrowse4)
	ON_BN_CLICKED(IDC_GZ, OnGz)
	ON_BN_CLICKED(IDC_UNGZ, OnUngz)
	ON_BN_CLICKED(IDC_RC4, OnRc4)
	ON_BN_CLICKED(IDC_UNRC4, OnUnRc4)
	ON_BN_CLICKED(IDC_ZIP, OnZip)
	ON_BN_CLICKED(IDC_UNZIP, OnUnzip)
	ON_BN_CLICKED(IDC_ZIP3, OnSecureZip)
	ON_BN_CLICKED(IDC_UNZIP3, OnSecureUnzip)
	ON_BN_CLICKED(IDC_Q1, OnQuery1)
	ON_BN_CLICKED(IDC_Q2, OnQuery2)
	ON_BN_CLICKED(IDC_Q3, OnQuery3)
	ON_BN_CLICKED(IDC_Q4, OnQuery4)
	ON_BN_CLICKED(IDC_DEFAULTS1, OnDefaults1)
	ON_BN_CLICKED(IDC_DEFAULTS2, OnDefaults2)
	ON_BN_CLICKED(IDC_DEFAULTS3, OnDefaults3)
	ON_BN_CLICKED(IDC_DEFAULTS4, OnDefaults4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CZTDlg::CZTDlg(CWnd* pParent /*=NULL*/): CDialog(CZTDlg::IDD, pParent)
	{
	//{{AFX_DATA_INIT(CZTDlg)
	m_strSrcFile1 = _T("");
	m_strSrcFile2 = _T("");
	m_strSrcFile3 = _T("");
	m_strArcFile  = _T("");
	m_strPassword = _T("");
	m_bStripPath = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	}

void CZTDlg::DoDataExchange(CDataExchange* pDX)
	{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZTDlg)
	DDX_Text(pDX, IDC_INFILE1, m_strSrcFile1);
	DDX_Text(pDX, IDC_INFILE2, m_strSrcFile2);
	DDX_Text(pDX, IDC_INFILE3, m_strSrcFile3);
	DDX_Text(pDX, IDC_OUTFILE, m_strArcFile);
	DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
	DDX_Check(pDX, IDC_STRIPPATH, m_bStripPath);
	//}}AFX_DATA_MAP
	}

BOOL CZTDlg::OnInitDialog()
	{
	CDialog::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
		{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
			{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
			}
		}
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	return TRUE;  // return TRUE  unless you set the focus to a control
	}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CZTDlg::OnPaint() 
	{
	if (IsIconic())
		{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		}
	else
		{
		CDialog::OnPaint();
		}
	}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CZTDlg::OnQueryDragIcon()
	{
	return (HCURSOR) m_hIcon;
	}

void CZTDlg::OnBrowse1() 
	{
	CString sTmp = "AllFiles (*.*)|*.*||";
	CFileDialog cDlg (TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ENABLESIZING | OFN_SHOWHELP, sTmp);
	cDlg.m_ofn.lpstrTitle = "Open File";
	if (cDlg.DoModal() == IDCANCEL)
		return;
	m_strSrcFile1 = cDlg.m_ofn.lpstrFile;
	UpdateData (FALSE);
	}

void CZTDlg::OnBrowse2() 
	{
	CString sTmp = "AllFiles (*.*)|*.*||";
	CFileDialog cDlg (TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ENABLESIZING | OFN_SHOWHELP, sTmp);
	cDlg.m_ofn.lpstrTitle = "Open File";
	if (cDlg.DoModal() == IDCANCEL)
		return;
	m_strSrcFile2 = cDlg.m_ofn.lpstrFile;
	UpdateData (FALSE);
	}

void CZTDlg::OnBrowse3() 
	{
	CString sTmp = "AllFiles (*.*)|*.*||";
	CFileDialog cDlg (TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ENABLESIZING | OFN_SHOWHELP, sTmp);
	cDlg.m_ofn.lpstrTitle = "Open File";
	if (cDlg.DoModal() == IDCANCEL)
		return;
	m_strSrcFile3 = cDlg.m_ofn.lpstrFile;
	UpdateData (FALSE);
	}

void CZTDlg::OnBrowse4() 
	{
	CString sTmp = "AllFiles (*.*)|*.*||";
	CFileDialog cDlg (TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ENABLESIZING | OFN_SHOWHELP, sTmp);
	cDlg.m_ofn.lpstrTitle = "Open File";
	if (cDlg.DoModal() == IDCANCEL)
		return;
	m_strArcFile = cDlg.m_ofn.lpstrFile;
	UpdateData (FALSE);
	}

#define BUFFSIZE 1024

void CZTDlg::AddFile(LPCTSTR pszName) 
   {
	CFile cFile;
	char szBuff [BUFFSIZE];

	TRY
		{
		cFile.Open (pszName, CFile::modeRead);
		}
   CATCH(CFileException, pEx)
   	{
      pEx->ReportError();
		return;
   	}
   END_CATCH

	PSZ pszZipName = (PSZ)pszName;
	if (m_bStripPath)
		{
		// this chops off the leading path info
		PSZ p1 = strrchr (pszName, '\\');
		PSZ p2 = (p1 ? p1+1 : (PSZ)pszName);
		pszZipName = p2;
		}

	int iRet = m_zip.OpenNewFile (pszZipName, NULL, Z_DEFAULT_COMPRESSION, m_strPassword);

	UINT uReadSize = 1;
	while (uReadSize)
	   {
		uReadSize = cFile.Read (szBuff, BUFFSIZE);
 		m_zip.Write (szBuff, uReadSize);
	   }
	m_zip.CloseFile ();
	cFile.Close ();
  	}



void CZTDlg::OnZip() 
	{
	UpdateData (TRUE);

 	int iRet =  m_zip.OpenArchive ((LPCTSTR)m_strArcFile, 1);
	AddFile ((LPCTSTR)m_strSrcFile1);
	AddFile ((LPCTSTR)m_strSrcFile2);
	AddFile ((LPCTSTR)m_strSrcFile3);
 	m_zip.CloseArchive ();
	}

void CZTDlg::ExtractFile() 
	{
	CFile cFile;
	char szFile [512];
	char szBuff [BUFFSIZE];
	char szComment[512];

	int i2 = m_zip.GetCurrentFileInfo (szFile, sizeof (szFile), szComment, sizeof (szComment));
	AfxMessageBox (szFile);

	TRY
		{
		cFile.Open (szFile, CFile::modeWrite | CFile::modeCreate);
		}
   CATCH(CFileException, pEx)
   	{
      pEx->ReportError();
		return;
   	}
   END_CATCH

	int i3 = m_zip.OpenCurrentFile (m_strPassword);
	int iReadSize = 1;
	while (iReadSize)
	   {
		iReadSize = m_zip.Read (szBuff, BUFFSIZE);
		if (iReadSize<0)
			{
			AfxMessageBox (CString("Problem reading file ")+szFile);
			return;
			}
 		cFile.Write (szBuff, iReadSize);
		}
	cFile.Close();
	int i4 = m_zip.CloseFile ();
	}

// list first
void CZTDlg::OnUnzip() 
	{
	UpdateData (TRUE);

 	int iRet =  m_zip.OpenArchive ((LPCTSTR)m_strArcFile, 0);
 	int i1 = m_zip.GotoFirstFile ();
	while (1)
	   {
		ExtractFile();
	 	if (m_zip.GotoNextFile ())
			break;
	   }
 	m_zip.CloseArchive ();
	}


//////////////////////////////////////////////////////


void CZTDlg::SecureAddFile(LPCTSTR pszName) 
   {
	CFile cFile;
	char szBuff [BUFFSIZE];

   cFile.Open (pszName, CFile::modeRead);

	// this chops off the leading path info
	PSZ p1 = strrchr (pszName, '\\');
	PSZ p2 = (p1 ? p1+1 : (PSZ)pszName);
	CString strZipName = p2;

	int iRet = m_SecureZip.OpenNewFile (strZipName, NULL, Z_DEFAULT_COMPRESSION, m_strPassword);
	UINT uReadSize = 1;
	while (uReadSize)
	   {
		uReadSize = cFile.Read (szBuff, BUFFSIZE);
 		m_SecureZip.Write (szBuff, uReadSize);
	   }
	m_SecureZip.CloseFile ();
	cFile.Close ();
  	}

void CZTDlg::OnSecureZip() 
	{
	UpdateData (TRUE);
 	int iRet =  m_SecureZip.OpenArchive ((LPCTSTR)m_strArcFile, 1);
	SecureAddFile ((LPCTSTR)m_strSrcFile1);
	SecureAddFile ((LPCTSTR)m_strSrcFile2);
	SecureAddFile ((LPCTSTR)m_strSrcFile3);
 	m_SecureZip.CloseArchive ();
	}


void CZTDlg::SecureExtractFile() 
	{
	CFile cFile;
	char szFile [512];
	char szBuff [BUFFSIZE];
	char szComment[512];

	int i2 = m_SecureZip.GetCurrentFileInfo (szFile, sizeof (szFile), szComment, sizeof (szComment));

	int iLen = strlen (szFile);
	if (iLen > 7 && !stricmp (szFile+iLen-7, ".gz.enc"))
		szFile[iLen-7] = '\0';

	cFile.Open (szFile, CFile::modeWrite | CFile::modeCreate);
	int i3 = m_SecureZip.OpenCurrentFile (m_strPassword);
	PSZ psz;
	switch (i3)
	   {
		case -1: psz = "password key needed"; 			break;
		case -2: psz = "incorrect password"; 			break;
		case -3: psz = "problem reading zip"; 			break;
		case -4: psz = "problem reading file in zip";break;
		case -5: psz = "internal problem"; 				break;
		default: psz = NULL;
	   }
	AfxMessageBox (psz ? psz : CString("Extracting ")+szFile);
	if (psz)
		return;

	int iReadSize = 1;
	while (iReadSize)
	   {
		iReadSize = m_SecureZip.Read (szBuff, BUFFSIZE);
		if (iReadSize<0)
			{
			AfxMessageBox (CString("Problem reading file ")+szFile);
			return;
			}
 		cFile.Write (szBuff, iReadSize);
		}
	cFile.Close();
	int i4 = m_SecureZip.CloseFile ();
	}

void CZTDlg::OnSecureUnzip() 
	{
	UpdateData (TRUE);

 	int iRet =  m_SecureZip.OpenArchive ((LPCTSTR)m_strArcFile, 0);
 	int i1 = m_SecureZip.GotoFirstFile ();
	while (1)
	   {
		SecureExtractFile();
	 	if (m_SecureZip.GotoNextFile ())
			break;
	   }
 	m_SecureZip.CloseArchive ();
	}

void CZTDlg::OnGz() 
	{
	char szBuff [BUFFSIZE];

	UpdateData (TRUE);

	BOOL bEncrypt = !m_strPassword.IsEmpty ();

	int iRet;
  	if (bEncrypt)
	  	iRet = m_SecureGZ.Open (m_strArcFile, "wb", m_strPassword);
	else
	  	iRet = m_GZ.Open (m_strArcFile, "wb");
	if (iRet)
		AfxMessageBox ("Open error");

	CFile cFile;
   cFile.Open (m_strSrcFile1, CFile::modeRead);
	UINT uReadSize = 1;
	while (uReadSize)
	   {
		uReadSize = cFile.Read (szBuff, BUFFSIZE);
	  	if (bEncrypt)
 			m_SecureGZ.Write (szBuff, uReadSize);
		else
 			m_GZ.Write (szBuff, uReadSize);
	   }
  	if (bEncrypt)
		m_SecureGZ.Close ();
	else
		m_GZ.Close ();
	cFile.Close ();
	}


void CZTDlg::OnUngz() 
	{
	char szBuff [BUFFSIZE];

	UpdateData (TRUE);

	BOOL bEncrypted = !m_strPassword.IsEmpty ();

	int iRet;
  	if (bEncrypted)
	  	iRet = m_SecureGZ.Open (m_strArcFile, "rb", m_strPassword);
	else
	  	iRet = m_GZ.Open (m_strArcFile, "rb");
	if (iRet)
		AfxMessageBox ("Open error");


	CFile cFile;
   cFile.Open (m_strSrcFile1, CFile::modeWrite | CFile::modeCreate);
	UINT uReadSize = 1;
	while (uReadSize)
	   {
	  	if (bEncrypted)
 			uReadSize = m_SecureGZ.Read (szBuff, BUFFSIZE);
		else
 			uReadSize = m_GZ.Read (szBuff, BUFFSIZE);
		cFile.Write (szBuff, uReadSize);
	   }
  	if (bEncrypted)
		m_SecureGZ.Close ();
	else
		m_GZ.Close ();
	cFile.Close ();
	///...
	}



void CZTDlg::Rc4EncryptFile (CString strInFile, CString strOutFile) 
	{
	CRC4 cRC4;
	char szBuff [BUFFSIZE];

	cRC4.InitStream ((BYTE*)(LPCTSTR)m_strPassword);

	CFile cInFile;
	TRY {cInFile.Open (strInFile, CFile::modeRead);}
   CATCH(CFileException, pEx)
   	{
      pEx->ReportError();
		return;
   	}
   END_CATCH

	CFile cOutFile;
	TRY {cOutFile.Open (strOutFile, CFile::modeWrite | CFile::modeCreate);}
   CATCH(CFileException, pEx)
   	{
      pEx->ReportError();
		cInFile.Close();
		return;
   	}
   END_CATCH

	int iReadSize = 1;
	while (iReadSize)
	   {
		iReadSize = cInFile.Read (szBuff, BUFFSIZE);
		cRC4.CryptStreamInPlace ((BYTE*)szBuff, iReadSize);
 		cOutFile.Write (szBuff, iReadSize);
	   }
	cInFile.Close();
	cOutFile.Close();
	}


void CZTDlg::OnRc4() 
	{
	Rc4EncryptFile (m_strSrcFile1, m_strArcFile);
	}

void CZTDlg::OnUnRc4() 
	{
	Rc4EncryptFile (m_strArcFile, m_strSrcFile1);
	}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void CZTDlg::OnQuery1() 
	{
	CInfoDialog cDlg;
	cDlg.m_strMsg = 
		"[GZip]\r\n"
		" Input: Source File 1\r\n"
		"Output: Archive File\r\n"
		"\r\n"
		"GZips the file.\r\n"
		"If Password field is non-blank, the file is also RC4 encrypted.\r\n"
		"\r\n"
		"[UnGZip]\r\n"
		" Input:Archive File\r\n"
		"Output:  Source File 1\r\n"
		"\r\n"
		"Un-GZips the file.\r\n"
		"If Password field is non-blank, the file is assumed to be RC4 encrypted.\r\n";
	cDlg.DoModal ();
	}

void CZTDlg::OnQuery2() 
	{
	CInfoDialog cDlg;
	cDlg.m_strMsg =
		"[Crypt]\r\n"
		" Input: Source File 1\r\n"
		"Output: Archive File\r\n"
		"\r\n"
		"RC4 Encrypts the file using password.\r\n"
		"\r\n"
		"[Un-Crypt]\r\n"
		" Input:Archive File\r\n"
		"Output:  Source File 1\r\n"
		"\r\n"
		"RC4 Decrypts the file using password.\r\n"
		"RC4 encryption == Descrption The only difference here\r\n"
		"is that Archive is used as the source, and Source File 1\r\n"
		"is used as the output\r\n";
	cDlg.DoModal ();
	}

void CZTDlg::OnQuery3() 
	{
	CInfoDialog cDlg;
	cDlg.m_strMsg =
		"[Zip]\r\n"
		" Input: Source File 1, 2, and 3\r\n"
		"Output: Archive File\r\n"
		"\r\n"
		"Zips the files. If Password field is non-blank, the individual files\r\n"
		"withing the zip archive are RC4 encrypted.  This will result in a file\r\n"
		"that has a valid Zip table of contents, but is NOT A VALID ZIP FILE.\r\n"
		"\r\n"
		"[UnZip]\r\n"
		" Input: Archive File\r\n"
		"Output: (derived from zip contents)\r\n"
		"\r\n"
		"UnZips the files. If Password field is non-blank, the individual files\r\n"
		"withing the zip archive are assumed to be RC4 encrypted.\r\n";
	cDlg.DoModal ();
	}


void CZTDlg::OnQuery4() 
	{
	CInfoDialog cDlg;
	cDlg.m_strMsg =
		"[SecureZip]\r\n"
		" Input: Source File 1, 2, and 3\r\n"
		"Output: Archive File\r\n"
		"\r\n"
		"Zips the files. If Password field is non-blank, the individual files\r\n"
		"are GZipped, RC4 encrypted, and added to the zip file.  This results\r\n"
		"in a valid zip file.\r\n"
		"\r\n"
		"[SecureUnZip]\r\n"
		" Input: Archive File\r\n"
		"Output: (derived from zip contents)\r\n"
		"\r\n"
		"UnZips the files. the individual files will be unzipped, unencrypted,\r\n"
		"and un GZipped as needed.\r\n";
	cDlg.DoModal ();
	}

#define DEF_PATH  CString("C:\\ZipTests\\")

void CZTDlg::OnDefaults1() 
	{
	UpdateData (TRUE);
	m_strSrcFile1 = DEF_PATH + "File1.txt";
	m_strSrcFile2 = "";
	m_strSrcFile3 = "";
	m_strArcFile  = DEF_PATH + "File1.txt.GZ";
	m_strPassword = "";
	UpdateData (FALSE);
	}

void CZTDlg::OnDefaults2() 
	{
	UpdateData (TRUE);
	m_strSrcFile1 = DEF_PATH + "File1.txt";
	m_strSrcFile2 = "";
	m_strSrcFile3 = "";
	m_strArcFile  = DEF_PATH + "File1.txt.rc4";
	m_strPassword = "password";
	UpdateData (FALSE);
	}

void CZTDlg::OnDefaults3() 
	{
	UpdateData (TRUE);
	m_strSrcFile1 = DEF_PATH + "File1.txt";
	m_strSrcFile2 = DEF_PATH + "File2.txt";
	m_strSrcFile3 = DEF_PATH + "File3.txt";
	m_strArcFile  = DEF_PATH + "Test1.zip";
	m_strPassword = "";
	UpdateData (FALSE);
	}

void CZTDlg::OnDefaults4() 
	{
	UpdateData (TRUE);
	m_strSrcFile1 = DEF_PATH + "File1.txt";
	m_strSrcFile2 = DEF_PATH + "File2.txt";
	m_strSrcFile3 = DEF_PATH + "File3.txt";
	m_strArcFile  = DEF_PATH + "Test2.zip";
	m_strPassword = "password";
	UpdateData (FALSE);
	}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
