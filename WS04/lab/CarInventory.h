#ifndef SDDS_HEADER_H
#define SDDS_HEADER_H

namespace sdds
{
	class CarInventory
	{
	private:
		char* m_type{};
		char* m_brand{};
		char* m_model{};
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price);
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		CarInventory(const char* type, const char* brand, const char* model);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
		~CarInventory();
	};

	int find_similar(CarInventory car[], const int num_cars);
}
#endif // !SDDS_HEADER_H
