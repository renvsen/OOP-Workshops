/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name:	Rendell Velasco
// Email:	rvelasco6@myseneca.ca
// Date:	23/09/23
// Citation: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#include <iostream>
#include "File.h"

namespace sdds {

   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   int noOfRecords()
   {
       int noOfRecs = 0;
       char ch;
       while (fscanf(fptr, "%c", &ch) == 1) {
           noOfRecs += (ch == '\n');
       }
       rewind(fptr);
       return noOfRecs;
   }

   bool read(char*& postal)
   {
       int size = 0;
       char cArr[4];
       if (fscanf(fptr, "%3s,", cArr))
       {
           //std::cout << cArr << std::endl; // remove later
           if ((size = strlen(cArr)))
           {
               
           }
           else
           {
               size = 0;
           }

           postal = new char[size + 1];
           strcpy(postal, cArr);

           /*std::cout << postal << std::endl;*/

           return 1;
       }
       else
       {
           return 0;
       }

   }

   bool read(int& population)
   {

       if (fscanf(fptr, "%d\n", &population))
       {
           return 1;
       }
       else
       {
           return 0;
       }
   }
}