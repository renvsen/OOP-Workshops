#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <fstream>
#include <iomanip>
#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape
	{
	private:
		int m_width{};
		int m_height{};
	public:
		Rectangle();
		~Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr);
	};


}
#endif // !SDDS_RECTANGLE_H

