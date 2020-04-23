// Workshop 6 - STL Containers
//Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
// Seneca email: lgonzaga-altermann@myseneca.ca
// Date of completion: march 09, 2020
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_RECECAR_H
#define SDDS_RECECAR_H
#include <iostream>
#include "Car.h"
using namespace std;

namespace sdds
{
	class Racecar :public Car
	{
	private:
		
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed()const;

	};
}

#endif
