#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "HealthCard.h"

using namespace std;

namespace sdds {

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		bool validVCode = false;
		bool validSNumber = false;

		int i = 0, j = 0;
		for (i = 0, j = 0; this->m_vCode[i] != '\0' && j != 2; i++, j++)
		{
			if (isalpha(vCode[i]))
			{
				validVCode = true;
			}
			else
			{
				validVCode = false;
			};
		}

		for (int i = 0, j = 0; this->m_sNumber[i] != '\0' && j != 9; i++, j++)
		{
			if (isalpha(this->m_sNumber[i]))
			{
				validSNumber = true;
			}
			else
			{
				validSNumber = false;
			};
		}

		return ((this->m_name != NULL && this->m_name != "") &&
			(this->m_number > 999999999 && this->m_number < 9999999999) &&
			(validVCode && validSNumber));
	}

	void HealthCard::setEmpty()
	{
		this->m_name = nullptr;
	}

	void HealthCard::allocateAndCopy(const char* name)
	{
		delete[] this->m_name;
		this->m_name = new char[strlen(name) + 1];
		strcpy(this->m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const
	{
		char next;
		next = cin.peek();

		if (next == ch)
		{
			istr.ignore();
		}
		else
		{
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(ostream& ostr) const
	{
		return ostr << this->m_number << "-" << this->m_vCode << ", " << this->m_sNumber << endl;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		if (validID(name, number, vCode, sNumber))
		{
			this->allocateAndCopy(name);
			this->m_number = number;
			strcpy(this->m_vCode, vCode);
			strcpy(this->m_sNumber, sNumber);
		}
		else
		{
			delete[] this->m_name;
			this->setEmpty();
		}
	}

	HealthCard::HealthCard()
	{
		this->set(nullptr, 0, {}, {});
	}

	HealthCard::HealthCard(const char m_name[] = nullptr, long long m_number = 0, const char m_vCode[] = {}, const  char m_sNumber[] = {})
	{
		this->set(m_name,m_number, m_vCode, m_sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc)
	{
		if (*this == hc)
		{
			*this = hc;
		}
		
	}

	HealthCard::~HealthCard()
	{
		delete[] this->m_name;
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc)
	{

		if (hc.validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber))
		{
			this->allocateAndCopy(hc.m_name);
			this->m_number = hc.m_number;
			strcpy(this->m_vCode, hc.m_vCode);
			strcpy(this->m_sNumber, hc.m_sNumber);
		}

		return *this;
	}

	HealthCard::operator bool() const { return (this->m_name != nullptr); }

	ostream& HealthCard::print(ostream& ostr, bool toFile = true) const
	{
		if (toFile)
		{
			ostr << this->m_name << ",";
			this->printIDInfo(ostr);
		}
		else
		{
			ostr << setw(50) << setfill('.') << left << this->m_name;
			this->printIDInfo(ostr);
		}

		return ostr;
	}
	istream& HealthCard::read(istream& istr)
	{
		char m_name[MaxNameLength+1];
		long long m_number;
		char m_vCode[3];
		char m_sNumber[10];

		cin.get(m_name,MaxNameLength+1, ',');
		extractChar(istr,',');

		istr >> m_number;
		extractChar(istr, '-');

		cin.get(m_vCode, 3, ',');
		extractChar(istr,',');

		cin.get(m_sNumber, 10, '\n');

		if (istr)
		{
			this->set(m_name, m_number, m_vCode, m_sNumber);
		}

		istr.clear();
		istr.ignore('\n');
	
		return istr;
	}

	ostream& operator<<(ostream& ostr, const HealthCard& hc)
	{
		if (hc)
		{
			hc.print(ostr, false);
		}
		else
		{
			ostr << "Invalid Card Number";
		}

		return ostr;
	}

	istream& operator>>(istream& istr, HealthCard& hc)
	{
		return hc.read(istr);
	}

	

}