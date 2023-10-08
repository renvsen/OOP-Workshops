#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
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
		setInfo(type, brand, model, year, code, price);
	}
	CarInventory::CarInventory(const char* type, const char* brand, const char* model)
	{
		CarInventory::resetInfo();
		if (type != NULL)
		{
			this->m_type = new char[strlen(type) + 1];
			strcpy(this->m_type, type);
		}
		if (brand != NULL)
		{
			this->m_brand = new char[strlen(brand) + 1];
			strcpy(this->m_brand, brand);
		}

		if (model != NULL)
		{
			this->m_model = new char[strlen(model) + 1];
			strcpy(this->m_model, model);
		}

		this->m_year = 2022;
		this->m_code = 100;
		this->m_price = 1;
	}
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		resetInfo();
		if (type != NULL)
		{
			this->m_type = new char[strlen(type) + 1];
			strcpy(this->m_type, type);
		}
		if (brand != NULL)
		{
			this->m_brand = new char[strlen(brand) + 1];
			strcpy(this->m_brand, brand);
		}

		if (model != NULL)
		{
			this->m_model = new char[strlen(model) + 1];
			strcpy(this->m_model, model);
		}

		if (year >= 1990)
		{
			this->m_year = year;
		}

		if (code < 999 && code > 99)
		{
			this->m_code = code;
		}

		if (price > 0.0)
		{
			this->m_price = price;
		}
		
		return *this;
	}
	void CarInventory::printInfo() const
	{
		
		cout << "| " << setw(10) << left << this->m_type << " | " << setw(16) << left << this->m_brand << " | " << setw(16) << left << this->m_model << " | "
			<< setw(4) << this->m_year << " | " << setw(4) << right << this->m_code << " | " << setw(9) << fixed <<showpoint << setprecision(2) << this->m_price << " |" << endl;
	}
	bool CarInventory::isValid() const
	{
		bool flag = false;

		if (this->m_type != NULL && this->m_brand != NULL && this->m_model != NULL && this->m_year >= 1990 && this->m_code < 999 && this->m_code > 99 && this->m_price > 0)
		{
			flag = true;
		}

		return flag;
	}
	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		bool flag = false; 
		if (this->m_type != nullptr && this->m_brand != nullptr && this->m_model != nullptr &&
			car.m_type != nullptr && car.m_brand != nullptr && car.m_model != nullptr)
		{
			if (strcmp(this->m_type, car.m_type) == 0 && strcmp(this->m_brand, car.m_brand) == 0 && strcmp(this->m_model, car.m_model) == 0 &&
				this->m_year == car.m_year)
			{
				flag = true;
			}
		}

		return flag;
	}
	void CarInventory::resetInfo()
	{

		if (this->m_type != nullptr && this->m_brand != nullptr && this->m_model != nullptr)
		{
			delete[] this->m_type;
			delete[] this->m_brand;
			delete[] this->m_model;

		}

		this->m_type = nullptr;
		this->m_brand= nullptr;
		this->m_model = nullptr;
		this->m_year = 0;
		this->m_code= 0;
		this->m_price = 0;

	}
	CarInventory::~CarInventory()
	{
		delete[] this->m_type;
		delete[] this->m_brand;
		delete[] this->m_model;
	}
	int find_similar(CarInventory car[], const int num_cars)
	{
		int match = 0;

		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					match = i;
				}
			}
		}
		return match;
	}

}