#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

namespace sdds {
	LblShape::LblShape()
	{

	}
	LblShape::LblShape(const char* label)
	{
		this->m_label = new char[strlen(label) + 1];
		strcpy(this->m_label, label);
	}
	LblShape::~LblShape()
	{
		delete[]this->m_label;
	}
	void LblShape::getSpecs(std::istream& istr)
	{
		char c;
		char string[1000];
		istr.getline(string, 1000, ',');
		istr >> c;
		istr.ignore(1);

		this->m_label = new char[strlen(string) + 1];
		strcpy(this->m_label, string);
	}
}
