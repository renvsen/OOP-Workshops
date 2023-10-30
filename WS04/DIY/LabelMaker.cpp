#include "LabelMaker.h"
#include "Label.h"

namespace sdds {

	LabelMaker::LabelMaker()
	{
		this->labelArr = nullptr;
		this->noOfLabels = 0;
	}
	LabelMaker::LabelMaker(int noOfLabels)
	{
		this->noOfLabels = noOfLabels;
		this->labelArr = new Label[noOfLabels];
	}
	void LabelMaker::readLabels()
	{
		std::cout << "Enter " << this->noOfLabels << " labels: " << std::endl;
		for (int i = 0; i < this->noOfLabels; i++)
		{
			std::cout << "Enter label number " << i + 1 << ":" << std::endl << "> ";
			this->labelArr[i].readLabel();
		}
	}
	void LabelMaker::printLabels()
	{
		for (int i = 0; i < this->noOfLabels; i++)
		{
			this->labelArr[i].printLabel();
			std::cout << std::endl;
			this->labelArr[i].finalize();
		}
	}
	LabelMaker::~LabelMaker()
	{
		for (int i = 0; i < this->noOfLabels; i++)
		{
			this->labelArr[i].setTextContent(nullptr);
		}
		delete[] this->labelArr;
	}
}