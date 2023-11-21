#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

namespace sdds {
	const char* LblShape::label()const
	{
		return this->m_label;
	}
	LblShape::LblShape()
	{
		this->m_label = nullptr;
	}
	LblShape::LblShape(const char* label)
	{
		this->m_label = new char[strlen(label) + 1];
		strcpy(this->m_label, label);
	}
	LblShape::~LblShape()
	{
		delete[]this->m_label;
		this->m_label = nullptr;
	}
	void LblShape::getSpecs(std::istream& istr)
	{
		std::string string{};
		std::getline(istr, string, ',');
		this->m_label = new char[string.length() + 1];
		strcpy(this->m_label, string.c_str());
	}
}
