// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include"SpellChecker.h"
using namespace std;
namespace sdds {

	SpellChecker::SpellChecker(const char* filename) 
	{

		ifstream file(filename);
		size_t index = 0;
		string obj;
		string message[10];

		if (!file)
		{

			throw "Bad file name!";
		}
		do {
			getline(file, obj);
			if (obj[0] != '\0')
			{
				message[index] = obj;
				index++;
			}

		} while (file);

		for (size_t i = 0; i < index; i++)
		{
			int bad = message[i].find(' ');
			m_badWords[i] = message[i].substr(0, bad);
			m_badWords[i].erase(0, m_badWords[i].find_first_not_of(" "));
			m_badWords[i].erase(m_badWords[i].find_last_not_of(" ") + 1);

			int good = message[i].find('\r', bad + 1);
			m_goodWords[i] = message[i].substr(bad + 1, good - bad - 1);
			m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(" "));
			m_goodWords[i].erase(m_goodWords[i].find_last_not_of(" ") + 1);

		}
		file.close();
	}
	void SpellChecker::operator()(std::string& text) const
	{
		size_t index = 0;
		
		for (size_t i = 0; i < 5; i++)
		{
			index = text.find(m_badWords[i]);// find the bad words
			while (index != std::string::npos)
			{
				text.replace(index, m_badWords[i].size(), m_goodWords[i]); // replacing the bad for good ones
				index = text.find(m_badWords[i]);
			}
		}
	}

}