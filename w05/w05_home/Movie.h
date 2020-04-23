// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
	class Movie
	{
	private:
		string m_title; // title of the movie
		size_t m_year; // year of release
		string m_description; // movie description
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template< typename T>
		void fixSpelling(T spellChecker) 
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif
