/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.1 (same as main_prof.cpp)
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name:	Rendell Velasco
// Email:	rvelasco6@myseneca.ca
// Date:	23/09/23
// Citation: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "Population.h"
using namespace sdds;
int main() {

   char code[4]{};
   while(getPostalCode(code)) {
      if(load("PCpopulationsComplete.csv", code)) {
         display();
      }
      deallocateMemory();

        if (load("PCpopulations.csv")) {
       
         display();

         }
   return 0;
}