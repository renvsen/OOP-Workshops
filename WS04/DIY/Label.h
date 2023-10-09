#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
#include <istream>

namespace sdds {

	class Label
	{
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		std::istream& readLabel();
		std::ostream& printLabel()const;
		Label& text(const char* content);
		~Label();
	private:
		const char* border;
		char* textContent;

	};




}
#endif // !SDDS_LABEL_H
