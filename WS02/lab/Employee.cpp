/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
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

#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;

   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employ) {
      bool ok = false;
      // return the combined success result of the three read functions. These read 
      // functions should set the properties of the reference argument of the load function

      if (read(employ.m_empNo) && read(employ.m_salary) && read(employ.m_name))
      {
          ok = true;
      }

      return ok;
   }

   bool load() {
      bool ok = false;


      if (openFile("employees.csv"))
      {
          noOfEmployees = noOfRecords();
          
          employees = new Employee[noOfEmployees];
          
          for (int i = 0; i < noOfEmployees; i++)
          {
              if(load(employees[i]))
              {
                ok = true;     
              }
              else
              {
                  cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                  i = noOfEmployees;
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

   void display(const Employee& employ)
   {

        cout << employ.m_empNo << ": " << employ.m_name << ", $" << (int)employ.m_salary << endl;
  
   }

   void display()
   {
       cout << "Employee Salary report, sorted by employee number" << endl << "no- Empno, Name, Salary" << endl << "------------------------------------------------"<< endl;
       sort();

       for (int i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
       
   }

   void deallocateMemory()
   {
       for (int i = 0; i < noOfEmployees; i++)
       {
           delete employees[i].m_name;
           employees[i].m_name = nullptr;
       }

       delete [] employees;
   }


}