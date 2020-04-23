// Workshop 6 - STL Containers
//Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
// Seneca email: lgonzaga-altermann@myseneca.ca
// Date of completion: march 04, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <sstream> // to use stringstream
#include "Vehicle.h"
#include "Car.h"
using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		
		string tmp;
		std::stringstream extraction;
		//peek() Returns the next character in the input sequence, without extracting it
		char c_tag = in.peek();
		if (c_tag == 'c' || c_tag == 'C')
		{
			getline(in, tmp);
			extraction << tmp;
			return new Car(extraction);
		}
		else
		{
			return nullptr;
		}
	}
}
