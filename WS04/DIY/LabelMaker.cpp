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

		//for (int i = 0; i < noOfLabels; i++)
		//{
		//	this->labelArr[i].Label::Label();
		//}
		
	}
	void LabelMaker::readLabels()
	{
		for (int i = 0; i < this->noOfLabels; i++)
		{
			this->labelArr[i].readLabel();
		}
	}
	void LabelMaker::printLabels()
	{
		for (int i = 0; i < this->noOfLabels; i++)
		{
			this->labelArr[i].printLabel();
		}
	}
	LabelMaker::~LabelMaker()
	{
		delete[] this->labelArr;
		this->labelArr = nullptr;

	}
}