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
#include <fstream>
#include "Car.h"

using namespace std;

namespace sdds 
{

	Car::Car(std::istream& in) 
	{
		// type of vehicle c_tag
		string tmp;
		getline(in, tmp);
		
		size_t tag = tmp.find(',');
		c_tag = tmp.substr(0, tag);
		c_tag.erase(0, c_tag.find_first_not_of(" "));
		c_tag.erase(c_tag.find_last_not_of(" ") + 1);

		if (c_tag == "r" || c_tag == "R") 
		{
			setRace(tmp);
		}

		// name of the company
		size_t maker = tmp.find(',', tag + 1);
		c_maker = tmp.substr(tag +1, maker - tag -1);
		c_maker.erase(0, c_maker.find_first_not_of(" "));
		c_maker.erase(c_maker.find_last_not_of(" ") + 1);

		// car condition
		size_t condition = tmp.find(',', maker + 1);
		c_condition = tmp.substr(maker + 1, condition - maker - 1);
		c_condition.erase(0, c_condition.find_first_not_of(" "));
		c_condition.erase(c_condition.find_last_not_of(" ") + 1);

		if (c_condition == " ") 
		{
			c_condition = "n";
		}
		else if(c_condition != "n" && c_condition != "u" && c_condition != "b")
		{
			throw 1;
		}
		// car speed
		size_t speed = tmp.find(',', condition + 1);
		try {
			c_topSpeed = stod(tmp.substr(condition + 1, speed - condition - 1));
		}
		catch (...)
		{
			throw 1;
		}
	}
	// conditions of the car
	std::string Car::condition() const 
	{
		
		std::string tmp = " ";
		if (c_condition == "n" || c_condition == " ")

			tmp = "new";

		else if (c_condition == "u")

			tmp = "used";

		else if (c_condition == "b")

			tmp = "broken";

		return nullptr;
	}
	// max speed of the car
	double Car::topSpeed() const
	{
		return c_topSpeed;
	}
	std::string Car::makers() const 
	{
		return c_maker;
	}
	void Car::setRace(std::string tmp) 
	{
		race = tmp;
	}
	std::string Car::getRace() const
	{
		return race;
	}

	void Car::display(std::ostream& out) const 
	{	
		out << "| "  << std::setw(10) <<right << makers()
			<< " | " << std::setw(6) << left <<condition()
			<< " | " << std::setw(6) << fixed << setprecision(2) << topSpeed()
			<< " |"  << endl;
	}
	   
	   
}