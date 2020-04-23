// Workshop 2 - Copy and Move Semantics
// w2_lab.cpp
// Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
/* Seneca email: lgonzaga-altermann@myseneca.ca*/
// Date of completion: 01/19/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <string>

namespace sdds
{

	class RecordSet
	{
	private:
		std::string* S;
		unsigned int rnumber;
	public:
		RecordSet();
		RecordSet(const char*);
		RecordSet(const RecordSet&);
		RecordSet& operator=(const RecordSet&);
		~RecordSet();
		size_t size() const;
		std::string getRecord(size_t);
	};
}

#endif

#pragma once
