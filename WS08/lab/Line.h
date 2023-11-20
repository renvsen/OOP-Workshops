#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds 
{
	class Line : public LblShape
	{
	private:
		int m_length;
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr);

	};

	Line::Line() : LblShape()
	{
		this->m_length = 0;
	}
	Line::Line(const char* label, int length) : LblShape(label)
	{
		this->m_length = length;
	}

}

#endif // !SDDS_LINE_H

