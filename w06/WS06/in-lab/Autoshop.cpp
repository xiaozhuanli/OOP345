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
#include <iomanip>
#include "Autoshop.h"
#include <vector>
using namespace std;

namespace sdds
{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) 
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const 
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			(*i)->display(out);
		}
		out << "--------------------------------" << endl;
	}
}