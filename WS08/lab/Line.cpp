#include "Line.h"

namespace sdds {
	Line::Line() : LblShape()
	{
		this->m_length = 0;
	}
	Line::Line(const char* label, int length) : LblShape(label)
	{
		this->m_length = length;
	}
	void Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> this->m_length;
		istr.ignore(1000,'\n');
	}
	void Line::draw(std::ostream& ostr)
	{
		if (this->m_length > 0 && this->label() != nullptr)
		{
			ostr << this->label() << std::endl;
			for (int i = 0; i < this->m_length; i++)
			{
				ostr << "=";
			}
		}
	}
}