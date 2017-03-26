/******************************************************************************
 * File:         display.c
 * Version:      1.3
 * Date:         2017-02-13
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS excercise 2: syntax check
 ******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "displayFunctions.h"

int main(int argc, char *argv[]) {
  unsigned long int argcl;
  char printMethod, printChar;
  ErrCode err;
  int niceincrement = strtoul(argv[3], NULL, 10);  //Nice string to unsigned long 
  err = SyntaxCheck(argc, argv);  // Check the command-line parameters
  if(err != NO_ERR) {
    DisplayError(err);        // Print an error message
  } 
  else {
    switch (fork ())    /*zowel parent als child 1 voeren switch uit*/
    {
      case -1:		/*initiële proces*/
        printf ("Helaas is de fork mislukt!\n");
      break;
      case 0:		/*child 1*/
	nice(niceincrement);
	printMethod = argv[1][0];
    	argcl = strtoul(argv[2], NULL, 10);  // String to unsigned long
    	printChar = argv[5][0];
      default:		/*parent*/
    	nice(0);
	printMethod = argv[1][0];
    	argcl = strtoul(argv[2], NULL, 10);  // String to unsigned long
    	printChar = argv[4][0];
	switch (fork ()) 			/*zowel parent als child 2 voeren switch uit*/
	{
	  case -1:	/*parent*/
	    printf ("Tweede fork is mislukt!\n");
	  break;
	  case 0:	/*child 2*/
	    nice(2*niceincrement);
	    printMethod = argv[1][0];
    	    argcl = strtoul(argv[2], NULL, 10);  // String to unsigned long
    	    printChar = argv[6][0];
	  break;
	  default:	/*parent*/
	    //printf("second default");
	  break;
        }
      break;
    }
    
    PrintCharacters(printMethod, argcl, printChar);  // Print character printChar argcl times using method printMethod
  }
  wait(NULL);
  wait(NULL);
  printf("\n");  // Newline at end
  return 0;
}

