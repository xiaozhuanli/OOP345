// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 01/05/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef  SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

namespace sdds
{
	class Reservation
	{
		private:
			string reservation_id; // array of characters
			string r_name; // the name of reservation
			string r_email; //email that can used to send the confirmation
			int r_people; // the number of people in the party
			int party_date; // the date of the party
			int party_hour; // the hour of the party
		public:
			// default constructor
			Reservation(); 
			// a constructor that receive the reservation
			Reservation(const std::string& res); 
			// A friend Helper that overload the insertion operator to insert the content
			friend std::ostream& operator<<(std::ostream& os, const Reservation&); //	
	};
}
#endif // ! SDDS_RESERVATION_H