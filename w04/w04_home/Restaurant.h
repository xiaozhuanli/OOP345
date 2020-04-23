// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef  SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"
using namespace std;
namespace sdds {
	class Restaurant {
		Reservation* rest;
		size_t num; // number of reservations
	public:
		Restaurant();
		~Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		size_t size() const;
		Restaurant(const Restaurant&);
		Restaurant(Restaurant&&);
		Restaurant& operator=(const Restaurant& );
		Restaurant& operator=(Restaurant&& );
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& );
	};
}
#endif // ! SDDS_RESTAURANT_H
