// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "ConfirmationSender.h"


namespace sdds 
{
	ConfirmationSender::ConfirmationSender() 
	{
		conf = nullptr;
		number = 0;
	}
	ConfirmationSender::~ConfirmationSender() 
	{
		delete[] conf;
		//conf = nullptr;
	}
	
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& obj)
	{
		number = obj.number;
		if (number > 0)
		{
			conf = const_cast<const Reservation**>(new Reservation * [number]);
			for (size_t i = 0; i < number; i++) 
			{
				conf[i] = obj.conf[i];
			}
		}
		else
		{
			conf = nullptr;
		}
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& move)
	{
		
			conf = move.conf;
			number = move.number;
			move.conf = nullptr;
			move.number = 0;
		
	}
	
	ConfirmationSender& ConfirmationSender::operator+=( const Reservation& obj)
	{
		bool not_found = true;

		for (size_t i = 0; i < number && not_found; i++) 
		{
			if (conf[i] == &obj)
			{
				not_found = false;
			}
		}

		if (not_found) {
			Reservation** tmp = new Reservation * [number + 1];

			for (size_t i = 0; i < number; i++) {
				tmp[i] = const_cast< Reservation*>(conf[i]);
			}

			delete[] conf;
			conf = const_cast<const Reservation**>(tmp);
			conf[number++] = &obj;
			
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation&  obj)
	{
		bool flag = true;
		size_t i = 0;
		for (; i < number && flag; i++) {

			if (conf[i] == &obj)
			{
				flag = false;
			}

		}
		if (!flag) 
		{
			Reservation** temp = new Reservation * [number--];
			if (i > 0) 
			{
				for (size_t j = 0; j < i; j++)
				{
					temp[j] = const_cast<Reservation*>(conf[j]);
				}
			}
			for (size_t j = i; j < number; j++) 
			{
				temp[j] = const_cast< Reservation*> (conf[j + 1]);
			}
			delete[] conf;
			conf = const_cast<const Reservation**> (temp);
		}
		return *this;
			
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj) 
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;

		if (obj.number == 0)
		{
			os << "The object is empty!" << endl;
		}
		else
		{
			for (size_t i = 0; i <obj.number; i++)
				os << *obj.conf[i];
		}
		os << "--------------------------" << std::endl;
		return os;
	}



}