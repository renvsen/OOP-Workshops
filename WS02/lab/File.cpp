/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
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
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    //TODO: read functions go here    
    bool read(int& employeeNum)
    {
        
        if (fscanf(fptr, "%d,", &employeeNum))
        {

            

            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool read(double& employeeSal)
    {
        
        if (fscanf(fptr, "%lf,", &employeeSal))
        {

          

            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool read(char*& name)
    {
        
        int size = 0;
        char cArr[128];
        if (fscanf(fptr, "%127[^\n]\n", cArr))
        {
            if((size = strlen(cArr)))
            {
                
            }
            else
            {
                size = 0;
            }

            name = new char[size + 1];
            strcpy(name, cArr);

            return 1;
        }
        else
        {
            return 0;
        }
        
    }



   
}