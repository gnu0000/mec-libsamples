// PKCTest.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "PKCTest.h"
#include "G_PKC.h"
#include "GnuArg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

int Usage ()
   {
   printf ("\nPKCTest  v0.1   testbed for PKC (Public Key Cryptography) module\n");
   printf ("USAGE: PKCTest <command> <params>\n");
   printf ("WHERE: <command> is one of\n");
   printf ("          /help .......... this help \n");
   printf ("          /genkey ........ create a key (needs id, pwd)\n");
   printf ("          /listkeys ...... list keys (optional id)\n");
   printf ("          /importkey ..... import a key file (needs infile, maybe pwd)\n");
   printf ("          /exportkey ..... export a key (needs id, outfile.  may need pwd)\n");
   printf ("          /deletekey ..... delete a key (needs id)\n");
   printf ("          /encrypt ....... encrypt a file (needs id, infile, outfile)\n");
   printf ("          /decrypt ....... decrypt a file (needs pwd, infile, outfile (?? id))\n");
   printf ("          /sign .......... sign a file (needs id, pwd, infile, outfile)\n");
   printf ("          /extractsig .... extract signature from file (infile, outfile)\n");
   printf ("          /info .......... get key info (needs id)\n");
   printf ("          /getnote ....... get a key note (needs id)\n");
   printf ("          /setnote ....... set a key note (needs id, pwd, note)\n");
   printf ("      <params> are 0 or more of\n");
   printf ("          /id=str ........ key id\n");
   printf ("          /pwd=str ....... passphrase\n");
   printf ("          /infile=str .... input file\n");
   printf ("          /outfile=str ... output file\n");
   printf ("          /note=str ...... arbitrary string\n");
   printf ("          /includeprivate  include private key on export\n");
   printf ("          /format=# ...... input file format (for import key).  Values:\n");
   printf ("               0 - COMPATIBLE .. PGP native formats (default)\n");
   printf ("               1 - PEM ......... X.509 data base 64 encoded per PEM\n");
   printf ("               2 - PKCS7 ....... PKCS-7 wrapped X.509 data\n");
   printf ("               3 - PKCS8 ....... X.509 private key data in PKCS-8\n");
   printf ("               4 - PKCS12 ...... X.509 private key data in PKCS-12\n");

   exit (0);
   }

extern "C" int _pfnCreateKeyInfo (int iType, int iVal)
   {
   printf (".");
   return 0;
   }


int GenKey (CPKC* pPKC, PSZ pszID, PSZ pszPWD)
   {
   printf ("[GenKey id=%s pwd=%s]\n", pszID, pszPWD);

   /// first gather entroy as needed
   printf ("Generating entropy");
   for (; pPKC->GetEntropyAvailable () < pPKC->GetEntropyNeeded (); pPKC->AddEntropy (PGP_EN_MOUSE))
      printf (".");
   printf ("\n");

   printf ("Creating Key");
	int err = pPKC->CreateKey (pszID, pszPWD, _pfnCreateKeyInfo);
   printf ("\n");
   printf ("CreateKey returned: %d [%s]\n", err, pPKC->GetError());
   return 0;
   }


int ListKeys (CPKC* pPKC, PSZ pszID)
   {
   printf ("[ListKeys id=%s]\n", pszID);

   CStringArray cMatchList;
	int err = pPKC->GetKeyMatchList (pszID, &cMatchList);
   printf ("GetKeyMatchList returned: %d [%s]\n", err, pPKC->GetError());
   for (int i=0; i<cMatchList.GetSize(); i++)
      {
      CString str = cMatchList.ElementAt (i);
      printf ("%d> %s\n", i+1, (LPCTSTR)str);
      }
   return 0;
   }


int ImportKey (CPKC* pPKC, PSZ pszInFile, int iFormat, PSZ pszPWD)
   {
   printf ("[ImportKey infile=%s format = %d pwd=%s]\n", pszInFile, iFormat, pszPWD);

   int iPGPFormat;
   switch (iFormat)
      {
      case 1:  iPGPFormat = PGPIMPORT_FORMAT_PEM       ; break;
      case 2:  iPGPFormat = PGPIMPORT_FORMAT_PKCS7     ; break;
      case 3:  iPGPFormat = PGPIMPORT_FORMAT_PKCS8     ; break;
      case 4:  iPGPFormat = PGPIMPORT_FORMAT_PKCS12    ; break;
      default: iPGPFormat = PGPIMPORT_FORMAT_COMPATIBLE; break;
      }
   char szKeyName [256];
	int err = pPKC->ImportKey (pszInFile, iPGPFormat, pszPWD, szKeyName);
   printf ("ImportKey returned: %s (%d [%s])\n", szKeyName, err, pPKC->GetError());
   return 0;
   }


int ExportKey (CPKC* pPKC, PSZ pszID, PSZ pszPWD, PSZ pszOutFile, BOOL bIncludePrivate)
   {
   printf ("[ExportKey id=%s pwd=%s outfile=%s]\n", pszID, pszPWD, pszOutFile);

	int err = pPKC->ExportKey (pszID, pszOutFile, bIncludePrivate);
   printf ("ExportKey returned: %d [%s]\n", err, pPKC->GetError());
   return 0;
   }


int DeleteKey (CPKC* pPKC, PSZ pszID)
   {
   printf ("[DeleteKey id=%s]\n", pszID);

	int err = pPKC->DeleteKey (pszID);
   printf ("DeleteKey returned: %d [%s]\n", err, pPKC->GetError());
   return 0;
   }


int Encrypt (CPKC* pPKC, PSZ pszID, PSZ pszInFile, PSZ pszOutFile)
   {
   printf ("[Encrypt id=%s infile=%s outfile=%s]\n", pszID, pszInFile, pszOutFile);

	int err = pPKC->ClearEncryptKeys ();
   if (err) printf ("ClearEncryptKeys returned: %d [%s]\n", err, pPKC->GetError());

	err = pPKC->AddEncryptKeyFromKeyRing (pszID);
   if (err) printf ("AddEncryptKeyFromKeyRing returned: %d [%s]\n", err, pPKC->GetError());

	err = pPKC->EncryptFile (pszOutFile, pszInFile);
   printf ("EncryptFile returned: %d [%s]\n", err, pPKC->GetError());

  	//err = pPKC->ClearEncryptKeys ();
   //if (err) printf ("ClearEncryptKeys returned: %d [%s]\n", err, pPKC->GetError());

   return 0;
   }


int Decrypt (CPKC* pPKC, PSZ pszID, PSZ pszPWD, PSZ pszInFile, PSZ pszOutFile)
   {
   printf ("[Decrypt id=%s pwd=%s infile=%s outfile=%s]\n", pszID, pszPWD, pszInFile, pszOutFile);

	int err = pPKC->DecryptFile (pszOutFile, pszInFile, pszPWD);
   printf ("DecryptFile returned: %d [%s]\n", err, pPKC->GetError());

   return 0;
   }


int Sign (CPKC* pPKC, PSZ pszID, PSZ pszPWD, PSZ pszInFile, PSZ pszOutFile)
   {
   printf ("[Sign id=%s pwd=%s infile=%s outfile=%s]\n", pszID, pszPWD, pszInFile, pszOutFile);

	int err = pPKC->SignFile (pszOutFile, pszInFile, pszID, pszPWD);
   printf ("SignFile returned: %d [%s]\n", err, pPKC->GetError());

   return 0;
   }


int ExtractSig (CPKC* pPKC, PSZ pszInFile, PSZ pszOutFile)
   {
   char szSig [256];

   printf ("[ExtractSig infile=%s outfile=%s]\n", pszInFile, pszOutFile);
	int err = pPKC->ExtractSignature (pszOutFile, pszInFile, szSig);
   printf ("ExtractSignature returned: %d [%s] Signer: [%s]\n", err, pPKC->GetError(), szSig);

   return 0;
   }


int Info (CPKC* pPKC, PSZ pszID)
   {
   printf ("[Sign id=%s]\n", pszID);

	int err = pPKC->KeyInfo (pszID, FALSE);
   printf ("Info returned: %d [%s]\n", err, pPKC->GetError());

   return 0;
   }


int SetKeyNote (CPKC* pPKC, PSZ pszID, PSZ pszPWD, PSZ pszNote)
   {
   printf ("[SetKeyNote id=%s pwd=%s Note=%s]\n", pszID, pszPWD, pszNote);

   printf ("Generating entropy");
   for (; pPKC->GetEntropyAvailable () < pPKC->GetEntropyNeeded (); pPKC->AddEntropy (PGP_EN_MOUSE))
      printf (".");
   printf ("\n");

   int err = pPKC->SetKeyNotation (pszID, pszPWD, pszNote);
   printf ("SetKeyNote returned: %d [%s]\n", err, pPKC->GetError());

   return 0;
   }

int GetKeyNote (CPKC* pPKC, PSZ pszID)
   {
   printf ("[GetKeyNote id=%s]\n", pszID);

   char szNote [256];
   int err = pPKC->GetKeyNotation (pszID, szNote);
   printf ("GetKeyNote returned: %s (%d [%s])\n", szNote, err, pPKC->GetError());

   return 0;
   }



int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
   {
   AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0);

   ArgBuildBlk ("? *^help *^genkey *^listkeys *^importkey *^exportkey "
                "*^deletekey *^encrypt *^decrypt *^sign *^extractsig "
                "*^info *^getnote *^setnote "
                "*^note% *^id% *^newid% *^pwd% *^infile% *^outfile% *^includeprivate *^format%");

   if (ArgFillBlk (argv))
      printf (ArgGetErr ()), Usage ();

   PSZ pszID      = (ArgIs ("id")      ? ArgGet ("id"     , 0) : "");
   PSZ pszPWD     = (ArgIs ("pwd")     ? ArgGet ("pwd"    , 0) : "");
   PSZ pszInFile  = (ArgIs ("infile")  ? ArgGet ("infile" , 0) : "");
   PSZ pszOutFile = (ArgIs ("outfile") ? ArgGet ("outfile", 0) : "");
   PSZ pszNote    = (ArgIs ("note")    ? ArgGet ("note"   , 0) : "");
   int iFormat    = (ArgIs ("format")  ? atoi(ArgGet ("format", 0)) : 0);

   CPKC cPKC;
	int err = cPKC.IsError ();
   if (err) printf ("Init returned: %d [%s]\n", err, cPKC.GetError());
   err = cPKC.OpenKeyRing ("pubring.pkr", "secring.skr");
   if (err) printf ("OpenKeyRing returned: %d [%s]\n", err, cPKC.GetError());

   if (ArgIs ("?") || ArgIs ("help") || argc < 2)
      Usage ();
   if (ArgIs ("genkey"))
      GenKey (&cPKC, pszID, pszPWD);
   if (ArgIs ("listkeys"))
      ListKeys (&cPKC, pszID);
   if (ArgIs ("importkey"))
      ImportKey (&cPKC, pszInFile, iFormat, pszPWD);
   if (ArgIs ("exportkey"))
      ExportKey (&cPKC, pszID, pszPWD, pszOutFile, ArgIs ("includeprivate"));
   if (ArgIs ("deletekey"))
      DeleteKey (&cPKC, pszID);
   if (ArgIs ("encrypt"))
      Encrypt (&cPKC, pszID, pszInFile, pszOutFile);
   if (ArgIs ("decrypt"))
      Decrypt (&cPKC, pszID, pszPWD, pszInFile, pszOutFile);
   if (ArgIs ("sign"))
      Sign (&cPKC, pszID, pszPWD, pszInFile, pszOutFile);
   if (ArgIs ("extractsig"))
      ExtractSig (&cPKC, pszInFile, pszOutFile);
   if (ArgIs ("info"))
      Info (&cPKC, pszID);
   if (ArgIs ("getnote"))
      GetKeyNote (&cPKC, pszID);
   if (ArgIs ("setnote"))
      SetKeyNote (&cPKC, pszID, pszPWD, pszNote);

   err = cPKC.CloseKeyRing ();
   if (err) printf ("CloseKeyRing returned: %d [%s]\n", err, cPKC.GetError());

   printf ("Done.\n");
   return 0;
   }


