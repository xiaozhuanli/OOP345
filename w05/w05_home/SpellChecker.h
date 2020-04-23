// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once


#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>

using namespace std;

namespace sdds
{
	class SpellChecker
	{
	private:
		string m_badWords[5];
		string m_goodWords[5];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
#endif
