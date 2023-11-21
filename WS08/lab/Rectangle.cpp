#include "Rectangle.h"

namespace sdds
{
	Rectangle::Rectangle()
	{
		this->m_width = 0;
		this->m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
	{
		int length = strlen(this->label() + 2);
		if (height > 3 && width > length)
		{
			this->m_width = width;
			this->m_height = height;
		}
	}
	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> this->m_width;
		istr.ignore(1000,',');
		istr >> this->m_height;
		istr.ignore(1000, '\n');
	}
	void Rectangle::draw(std::ostream& ostr)
	{
		if (this->m_height != 0 && this->m_width != 0)
		{
			std::cout << '+';
			for (int i = 0; i < this->m_width - 2; i++)
			{
				std::cout << '-';
			}
			std::cout << '+' << std::endl;

			std::cout << '|' << std::setw(this->m_width - 2) << std::left << this->label() << '|' << std::endl;
			for (int i = 0; i < this->m_height - 3; i++)
			{
				std::cout << '|';
				for (int j = 0; j < this->m_width - 2; j++)
				{
					std::cout << ' ';
				}
				std::cout << '|' << std::endl;
			}

			std::cout << '+';
			for (int i = 0; i < this->m_width - 2; i++)
			{
				std::cout << '-';
			}
			std::cout << '+';
		}
	}
}