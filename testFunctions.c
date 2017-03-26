/******************************************************************************
 * File:         testFunctions.c
 * Version:      1.3
 * Datum:        2017-02-13
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS excercise 3:  definitions of test functions for display.c
 ******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "testFunctions.h"


// Test whether an argument has the correct value:
ErrCode TestType(char *printMethod) {
  ErrCode fout = NO_ERR;
  
  // Add the missing code
  if(*printMethod == 'e' || *printMethod == 'p' || *printMethod == 'w') {}
  else{
    fout = ERR_TYPE;
  }
  return fout;
}


// Test whether an argument contains a non-negative number:
ErrCode TestNr(char *numberOfTimes) {
  ErrCode fout = NO_ERR;
  int converter = atoi(numberOfTimes);
  if(converter % 2) {
    fout = ERR_NR;
  }
  // Add the missing code
  
  return fout;
}

ErrCode TestNice(char *niceIncrement){
  ErrCode fout = NO_ERR;
  int converter = atoi(niceIncrement);
  if((converter < 0) || (converter > 9)){
    fout = ERR_NICE;
  }

  return fout;
}


// Test whether an argument contains only one character:
ErrCode TestChar(char *printChar) {
  ErrCode fout = NO_ERR;
  if(strlen(printChar) != 1){
    fout = ERR_CHAR;
  }
  // Add the missing code
  
  return fout;
}
