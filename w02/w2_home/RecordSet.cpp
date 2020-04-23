// Workshop 2 - Copy and Move Semantics
// w2_lab.cpp
// Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
/* Seneca email: lgonzaga-altermann@myseneca.ca*/
// Date of completion: 01/26/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "RecordSet.h"
#include "TimedEvents.h"
using namespace std;

namespace sdds
{
	RecordSet::RecordSet()
	{
		S = nullptr;
		rnumber = 0;
	}
	RecordSet::RecordSet(const char* file_name)
	{
		rnumber = 0;
		S = nullptr;
		string temp;
		ifstream file;
		file.open(file_name);
		rnumber++;

		if (file.is_open()) {

			while (!file.eof())
			{

				getline(file, temp, ' ');
				if (!file.eof()) {

					temp.clear();
					rnumber++;

				}
			}
		}file.close();

		delete[] S;
		S = new std::string[rnumber];
		file.open(file_name);
		for (size_t i = 0; i < rnumber; ++i)
		{
			getline(file, S[i], ' ');
		}


	}
	RecordSet::RecordSet(const RecordSet& obj)
	{
		
		*this = obj;

	}
	RecordSet& RecordSet::operator=(const RecordSet& obj)
	{
		if (this != &obj)
		{
			
			if (obj.S != nullptr)
			{
				rnumber = obj.rnumber;
				delete[] S;
				S = new std::string[rnumber];

				for (size_t i = 0; i < rnumber; i++)
				{
					S[i] = obj.S[i];
				}
			}
		}
		else
		{
			S = nullptr;
			rnumber = 0;
		}
		return *this;
	}
	// destructor
	RecordSet::~RecordSet()
	{
		delete[] S;
		S = nullptr;
	}
	// returnthe size of the obj
	size_t RecordSet::size() const
	{
		return rnumber;
	}
	// get the index 
	std::string RecordSet::getRecord(size_t index)
	{

		if (index < rnumber)
		{
			return S[index];
		}
		else
		{

			return "";
		}
	}
	// move constructor
	RecordSet::RecordSet(RecordSet&& obj)
	{
		*this = std::move(obj);		
	}
	// move assignment 
	RecordSet& RecordSet::operator=(RecordSet&& obj)
	{
		
		if (this != &obj)
		{
				rnumber = obj.rnumber;
				S = new std::string[rnumber];

				for (size_t i = 0; i < rnumber; i++)
				{
					S[i] = obj.S[i];
				}
				obj.rnumber = 0;
				obj.S = nullptr;
						
		}
		return *this;
	}
	
}
