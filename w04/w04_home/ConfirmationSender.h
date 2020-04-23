// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef  SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
#include "ConfirmationSender.h"
using namespace std;
#pragma once

namespace sdds 
{
	class ConfirmationSender
	{
		private:
			const Reservation** conf;
			size_t number;
		public:
			ConfirmationSender();
			ConfirmationSender(const ConfirmationSender& );
			ConfirmationSender(ConfirmationSender&&);
			ConfirmationSender& operator+=(const Reservation&);
			ConfirmationSender& operator-=(const Reservation&);
			~ConfirmationSender();
			friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& );

	};
}
#endif // ! SDDS_CONFIRMATIONSENDER_H
