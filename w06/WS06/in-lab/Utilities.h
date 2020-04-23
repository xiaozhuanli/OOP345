// Workshop 6 - STL Containers
//Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
// Seneca email: lgonzaga-altermann@myseneca.ca
// Date of completion: march 04, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Vehicle.h"
#include "Car.h"
using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif
