#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <string.h>
#include "Label.h"

namespace sdds {

	const char* defBorder = "+-+|+-+|";

	Label::Label()
	{
		this->border = defBorder;
		this->textContent = nullptr;

	}
	Label::Label(const char* frameArg)
	{
		if (frameArg != nullptr)
		{
			this->border = frameArg;
		}
		else
		{
			this->border = defBorder;
		}
		this->textContent = nullptr;
	}
	Label::Label(const char* frameArg, const char* content)
	{
		Label::Label(frameArg);
		Label::text(content);
	}
	std::istream& Label::readLabel()
	{
		char tempLabel[70];
		std::cin >> tempLabel;
		this->textContent = new char[strlen(tempLabel) + 1];
		strcpy(this->textContent, tempLabel);
		return std::cin >> this->textContent;
	}
	std::ostream& Label::printLabel()const
	{
		if (this->textContent != nullptr)
		{
			std::cout << this->border[0] << std::setfill(this->border[1]) << std::setw(strlen(this->textContent) + 3) << this->border[2] << std::endl;
			std::cout << this->border[7] << std::setfill(' ') << std::setw(strlen(this->textContent) + 3) << this->border[3] << std::endl;
			std::cout << this->border[7] << " " << this->textContent << " " << this->border[3] << std::endl;
			std::cout << this->border[7] << std::setfill(' ') << std::setw(strlen(this->textContent) + 3) << this->border[3] << std::endl;
			std::cout << this->border[6] << std::setfill(this->border[5]) << std::setw(strlen(this->textContent) + 3) << this->border[4] << std::endl;
		}

		return std::cout;
	}
	Label& Label::text(const char* content)
	{
		this->textContent = new char[strlen(content) + 1];
		strcpy(this->textContent, content);

		return *this;
	}
	Label::~Label()
	{
		delete[] this->textContent;
	}
}