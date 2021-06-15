/*
 *
 * dis.c
 * Tuesday, 3/4/1997.
 * Craig Fitzgerald
 *
 *
 * This file contains several globals and is in general quite bulky
 * for speed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GnuType.h>
#include <GnuMisc.h>
#include <GnuArg.h>
#include "gclib.h"


void Usage (void)
   {
   printf ("DIS  Gnu GX module dissasembler                v0.1       %s %s\n\n", __DATE__, __TIME__);
   printf ("USAGE: DIS gxfile\n\n");
   printf ("WHERE: gxfile  is a module compiled with GC\n");
   exit (0);
   }

int main (int argc, char *argv[])
   {
   PSZ p;
	char szInFile[256];

   ArgBuildBlk ("? *^Help");

   if (ArgFillBlk (argv))
      Error (ArgGetErr (), 0, 0);

   if (ArgIs ("help") || ArgIs ("?") || !ArgIs(NULL))
      Usage ();

   strcpy (szInFile, ArgGet (NULL, 0));
   if (!(p = strrchr (szInFile, '\\')))
      p = szInFile;
   if (!strrchr (p, '.'))
      strcat (szInFile, EXT_EXE);

   DumpProgram (szInFile, NULL);
   return 0;
   }


