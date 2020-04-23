// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Restaurant.h"


namespace sdds 
{
	Restaurant::Restaurant()
	{
		rest = nullptr;
		num = 0;
	}
	Restaurant::~Restaurant() 
	{
		delete[] rest;
	
	}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) 
	{
		if (cnt > 0 && reservations != nullptr)
		{
			rest = new Reservation[cnt];
			num = 0;
			for (size_t i = 0u; i < cnt; i++)
			{
				rest[num] = *reservations[i];
				num++;
			}
		}
		else
		{
			*this = Restaurant();
		}
	}
	size_t Restaurant::size() const 
	{
		return num;
	}
	Restaurant::Restaurant(const Restaurant& obj) 
	{
		*this = obj;

	}
	Restaurant::Restaurant(Restaurant&& obj) 
	{
		*this = move(obj);
	}
	Restaurant& Restaurant::operator=(const Restaurant& obj)
	{
		if (this != &obj)
		{
			rest = new Reservation[obj.size()];
			num = obj.num;
			for (size_t i = 0u; i < num; i++)
			{
				rest[i] = obj.rest[i];
				
			}
		}
		return *this;
	}
	Restaurant& Restaurant::operator=(Restaurant&& obj) 
	{
		if (this != &obj) 
		{
			num = obj.num;
			rest = obj.rest;
			obj.num = 0;
			obj.rest = nullptr;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Restaurant& obj)
	{
		os << "--------------------------" << std::endl
			<< "Fancy Restaurant" << std::endl
			<< "--------------------------" << std::endl;
		if (obj.size() == 0)
		{
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < obj.num; i++)
			{
				os << obj.rest[i];
			}
		}
		os << "--------------------------" << std::endl;

		return os;

	}

}

	