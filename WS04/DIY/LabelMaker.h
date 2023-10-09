#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include"Label.h"

namespace sdds {

	class LabelMaker
	{
	public:
		LabelMaker();
		LabelMaker(int noOfLabels);
		void readLabels();	
		void printLabels();
		~LabelMaker();

	private:
		Label* labelArr;
		int noOfLabels;
	};
}
#endif // !SDDS_LABELMAKER_H
