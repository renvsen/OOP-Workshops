/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.h
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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();

   int noOfRecords();
   bool read(char*& postal);
   bool read(int& population);
  
}
#endif // !SDDS_FILE_H_
