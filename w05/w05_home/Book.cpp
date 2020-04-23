// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <string>
//#include <iostream>
#include <iomanip>
#include <algorithm>
#include"Book.h"

using namespace std;
namespace sdds {
	Book::Book() 
	{
		b_author = '\0';
		b_title = '\0';
		b_country = '\0';
		b_year = 0;
		b_price = 0;
		b_description = '\0';
	}
	const std::string& Book::title() const 
	{
		return b_title;
	}
	const std::string& Book::country() const 
	{
		return b_country;
	}
	const size_t& Book::year() const 
	{
		return b_year;
	}
	double& Book::price() 
	{
		return b_price;
	}
	Book::Book(const std::string& strBook) 
	{
		int author = strBook.find(',');
		b_author = strBook.substr(0, author);
		b_author.erase(0, b_author.find_first_not_of(" "));
		b_author.erase(b_author.find_last_not_of(" ") + 1);

		int title = strBook.find(',',author + 1);
		b_title = strBook.substr(author+1,title - author - 1);
		b_title.erase(0, b_title.find_first_not_of(" "));
		b_title.erase(b_title.find_last_not_of(" ") + 1);

		int country = strBook.find(',', title + 1);
		b_country = strBook.substr(title + 1, country - title - 1);
		b_country.erase(0, b_country.find_first_not_of(" "));
		b_country.erase(b_country.find_last_not_of(" ") + 1);

		int price = strBook.find(',', country + 1);
		b_price = stod(strBook.substr(country + 1, price - country - 1));

		int year = strBook.find(',', price + 1);
		b_year = stod(strBook.substr(price + 1, year - price - 1));

		int description = strBook.find('.', year + 1);
		b_description = strBook.substr(year + 1, description - year + 1);
		b_description.erase(0, b_description.find_first_not_of(" "));
		
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		 os << setw(20) << book.b_author << " | "
			<< setw(22) << book.b_title << " | "
			<< setw(5) << book.b_country << " | "
			<< setw(4) << book.b_year << " | "
			<< setw(6) << fixed << setprecision(2) << book.b_price << " | " 
			<< book.b_description << endl;
		return os;
	}
}
