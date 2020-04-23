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
			string reservation_id;
			string r_name;
			string r_email;
			int r_people;
			int party_date;
			int party_hour;
		public:
			Reservation();
			Reservation(const std::string& res);
			friend std::ostream& operator<<(std::ostream& os, const Reservation&);

		
	};
}
#endif // ! SDDS_RESERVATION_H