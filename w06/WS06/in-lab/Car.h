// Workshop 6 - STL Containers
//Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
// Seneca email: lgonzaga-altermann@myseneca.ca
// Date of completion: march 04, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

namespace sdds
{
	class Car :public Vehicle
	{
	private:
		string c_tag;
		string c_maker;
		string c_condition;
		double c_topSpeed;
	public:
		Car(std::istream& in);
		std::string condition() const;
		std::string makers() const;
		double topSpeed() const;
		void display(std::ostream& out) const;	
	};
}

#endif


