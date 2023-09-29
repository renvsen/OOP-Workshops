/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
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
#include <cstring>
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;

namespace sdds {

    int noOfRegions;
    Region* regions;
    int* populate;
    
   /* char test[4];
    */
    int allFlag = 0;

    void sort() {
        int i, j;
        Region temp;
        for (i = noOfRegions - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (regions[j].population> regions[j + 1].population) {
                    temp = regions[j];
                    regions[j] = regions[j + 1];
                    regions[j + 1] = temp;
                }
            }
        }
    }

   bool startsWith(const char* cstring, const char* subString) {
      return std::strstr(cstring, subString) == cstring;
   }

   bool getPostalCode(char* postal_code_prefix)
   {
       bool ok = true;
       allFlag = 0;
       char inputArr[4];
       cout << "Population Report" << endl << "-----------------" << endl << "Enter postal code:" << endl << "> ";
       fscanf(stdin, "%s", inputArr);
       strcpy(postal_code_prefix, inputArr);
       
       if (strcmp(postal_code_prefix, "all") == 0)
       {
           allFlag = 1;
       }

       if (strcmp(inputArr, "!") == 0)
       {
           ok = false;
       }

       return ok;
   }

   bool load(const char* filename, const char* partial_postal_code_prefix)
   {

       int j = 0;
       int nFound = 0;
       
       load(filename);

       for (int i = 0; i < noOfRegions; i++)
       {
           if (startsWith(regions[i].postal, partial_postal_code_prefix))
           {
               nFound++;
           }

       }

       populate = new int[nFound];

       for (int i = 0; i < noOfRegions; i++)
       {
           if (startsWith(regions[i].postal, partial_postal_code_prefix))
           {
                populate[j] = regions[i].population;
                j++;
           }
       }

       return 1;
   }

   bool load(const char* filename) {
       bool ok = false;

       if (openFile(filename))
       {
           noOfRegions = noOfRecords();
           

           regions = new Region[noOfRegions];

           for (int i = 0; i < noOfRegions; i++)
           {
               if (load(regions[i]))
               {
                   ok = true;
               }
               else
               {
                   cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                   i = noOfRegions;
                   deallocateMemory();
               }

           }
       }
       else
       {
           cout << "Could not open data file: data_file_name" << endl;
       }

       closeFile();

       return ok;
   }

   bool load(Region& region) {
       bool ok = false;
       // return the combined success result of the three read functions. These read 
       // functions should set the properties of the reference argument of the load function

       if (read(region.postal) && read(region.population))
       {
           ok = true;
       }

       return ok;
   }


   void display(const Region region)
   {
       cout << region.postal << ": " << region.population << endl;
   }

   void display() {
       
       //while (getPostalCode(test)) // used to test for the other main.cpp
       //{
           int j = 0;
           int noFound = 0;
           int total = 0;

           sort();

           cout << "Postal Code: population" << endl << "-------------------------" << endl;
           if (populate != NULL)
           {
               for (int i = 0; populate[i] != 0; i++)
               {
                   noFound++;
               }

               for (int i = 0; i < noFound; i++)
               {
                   if (regions[i].population == populate[j] || allFlag) 
                   {
                       cout << j + 1 << "- ";
                       display(regions[i]);
                       total += populate[j];
                       j++;
                   }
               }
           }
           else
           {
               for (int i = 0; i < noOfRegions; i++)
               {
                   if (allFlag)
                   {
                       cout << j + 1 << "- ";
                       display(regions[i]);
                       total += regions[i].population;
                       j++;
                   }
               }
           }

           cout << "-------------------------" << endl;
           cout << "Population of the listed areas: " << total << endl << endl;
       /*}*/                                         // used to test for the other main.cpp
   }



   void deallocateMemory()
   {
       for (int i = 0; i < noOfRegions; i++)
       {
           delete regions[i].postal;
           regions[i].postal = nullptr;
       }
       delete[] regions;

       /*delete[] populate;*/


       
       

       
       

   }
   
}