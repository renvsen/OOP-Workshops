/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
   
    struct Region {
        char* postal;
        int population;
    };

    //sorts the dynamic array of employees based on the GPA of the employees.
   void sort();

	// returns true of the cstring starts with subString
   bool startsWith(const char* cString, const char* subString);


   bool getPostalCode(char* postal_code_prefix);
   bool load(const char* filename, const char* partial_postal_code_prefix);
   bool load(const char* filename);
   bool load(Region& region);
   void display(const Region region);
   void display();
   void deallocateMemory();

   
   
}
#endif // SDDS_POPULATION_H_