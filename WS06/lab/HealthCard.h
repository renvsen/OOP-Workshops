#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

#include<stdio.h>
#include<iostream>

using namespace std;

namespace sdds 
{
   const int MaxNameLength = 55;
   class HealthCard
   {
   private:
       char* m_name{};
       long long m_number;
       char m_vCode[3];
       char m_sNumber[10];

       //Returns true is the four parts of the ID card are valid.
       bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;

       //Sets the HeathCard object to a recognizable empty (invalid) state by setting m_name to nullptr;
       void setEmpty();

       //Free the memory pointed by m_name
       //Allocate enough memory to store name Cstring
       //Copy the Cstring pointed by name into the newly allocated memory pointed by m_name
       void allocateAndCopy(const char* name);

       //"peek()" and see if the next character in the keyboard buffer is the same as the ch argument
       //    If it is the same, Remove it from the keyboard and throw it away!(i.e.istr.ignore())
       //    If not:
       //        Ignore all the remaining characters(up to 1000 characters) or the value of ch(use istr.ignore(int n, char c))
       //        Set the istream into a fail state(use istr.setstate(iso::failbit))
       void extractChar(istream& istr, char ch) const;


       //Inserts the three parts related to the main card number, version codeand stock number of the health card information into the istr object in the following format :
       //    1234567890 - AB, XY7652341
       //    and then returns the istr object reference
       ostream& printIDInfo(ostream& ostr)const;

       //Validates the arguments, reallocates memory for the nameand sets the object attributes to their corresponding values.
       //    If the nameand the three parts are valid(see Validation) call the private function to validate
       //        Calls the reallocateAndCopy function to set the name
       //        Sets the three parts to their values(m_number, m_vCode, m_sNumber)
       //    If not, it deletes the memory pointed by m_nameand sets the object to a safe empty state(setEmpty())
       void set(const char* name, long long number, const char vCode[], const char sNumber[]);


   public:

       //constructor
       HealthCard();
       HealthCard(const char m_name[], long long m_number, const char m_vCode[], const char m_sNumber[]);
       HealthCard(const HealthCard& hc);
       HealthCard& operator=(const HealthCard& hc);

       //deletes the memory pointed by m_name.
       ~HealthCard();


       //Boolean type conversion operator
       operator bool() const;

       ostream& print(ostream& ostr, bool toFile) const;
       istream& read(istream& istr);
   };

    //if hc is valid it will print it using the print function on the screen and not on File, (i.e. onFile is false). Otherwise, it will print "Invalid Card Number".
    //In the end, it will return the ostr reference.
   ostream& operator<<(ostream& ostr, const HealthCard& hc);

    //returns the read method of the hc argument.
   istream& operator>>(istream& istr, HealthCard& hc);


}
#endif // !SDDS_HealthCard_H


