// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <iomanip>
#include "Movie.h"
using namespace std;

namespace sdds
{
	Movie::Movie() 
	{
		m_title = '\0';
		m_year = 0;
		m_description = '\0';
	}
	const std::string& Movie::title() const
	{
		return m_title;
	}
	Movie::Movie(const std::string& strMovie)
	{
		int title = strMovie.find(',');
		m_title = strMovie.substr(0, title);
		m_title.erase(0, m_title.find_first_not_of(" "));
		m_title.erase(m_title.find_last_not_of(" ") + 1);

		int year = strMovie.find(',', title + 1);
		m_year = stod(strMovie.substr(title + 1, year - title - 1));

		int description = strMovie.find('.', year + 1);
		m_description.append(strMovie.substr(year + 1, description - year + 1));
		m_description.erase(0, m_description.find_first_not_of(" "));
	}
	std::ostream& operator<<(std::ostream& os, const Movie& movie) 
	{
		os << setw(40) << movie.m_title << " | "
			<< setw(4) << movie.m_year << " | "
			<< movie.m_description << endl;
		return os;
	}
}