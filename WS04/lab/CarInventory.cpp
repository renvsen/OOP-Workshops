#include <iostream>
#include "CarInventory.h"
using namespace std;

namespace sdds
{
	CarInventory::CarInventory()
	{
		CarInventory::resetInfo();
	}
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		CarInventory::resetInfo();
		if (type != NULL)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
		}
		if (brand != NULL)
		{
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
		}

		if (model != NULL)
		{
			m_model	= new char[strlen(model) + 1];
			strcpy(m_model, model);
		}

		if (year >=1990)
		{
			m_year = year;
		}

		if (code < 999 && code > 0 )
		{
			m_code = code;
		}

		if (price > 0)
		{
			m_price = price;
		}
	}
	CarInventory::CarInventory(const char* type, const char* brand, const char* model)
	{
		CarInventory::resetInfo();
		if (type != NULL)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
		}
		if (brand != NULL)
		{
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
		}

		if (model != NULL)
		{
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
		}

		m_year = 2022;
		m_code = 100;
		m_price = 1.0;
	}
	CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{

	}
	void CarInventory::printInfo() const
	{

	}
	bool CarInventory::isValid() const
	{

	}
	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{

	}
	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand= nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code= 0;
		m_price = 0.0;
	}
	CarInventory::~CarInventory()
	{

	}

	int find_similar(CarInventory car[], const int num_cars)
	{

	}
}