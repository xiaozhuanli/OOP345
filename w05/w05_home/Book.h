// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;

namespace sdds 
{
	class Book
	{
		private: 
			string b_author; // author name
			string b_title;// book title
			string b_country; // country of publication
			size_t b_year; // year of publication
			double b_price; // book price
			string b_description; // book summary
			
		public:
			Book();
			const std::string& title() const;
			const std::string& country() const;
			const size_t& year() const;
			double& price();
			Book(const std::string& strBook);
			Book& operator += (const Book& obj);
			friend std::ostream& operator<<(std::ostream& os, const Book& book);
			template <typename T>
			void fixSpelling(T spellChecker)
			{
				spellChecker(b_description);
			}
	};

}
#endif