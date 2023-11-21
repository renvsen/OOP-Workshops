#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <string>
#include <cstring>
#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape
	{
	private:
		char* m_label{};
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		void getSpecs(std::istream& istr);
		virtual void draw(std::ostream& ostr) = 0;
	};


}
#endif // !SDDS_LBLSHAPE_H

