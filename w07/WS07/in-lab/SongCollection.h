// Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
// Seneca email:lgonzaga-altermann@myseneca.ca
// Date of completion: march 11 - 2020
// Song Collection - Workshop 7 STL Algorithms
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

namespace sdds
{
	struct Song
	{
		std::string artist;
		std::string title;
		std::string album;
		double price;
		int release;
		int size;

	};
	class SongCollection
	{
	private:
		std::vector<Song> songs;
	public:
		SongCollection(char* obj);
		void display(std::ostream& out) const;

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif
