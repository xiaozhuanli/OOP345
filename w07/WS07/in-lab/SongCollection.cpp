// Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
// Seneca email:lgonzaga-altermann@myseneca.ca
// Date of completion: march 11 - 2020
// Song Collection
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <vector>
#include"SongCollection.h"
using namespace std;


namespace sdds
{
	SongCollection::SongCollection(char* obj)
	{
		Song temp;
		std::ifstream file(obj);
		if (!file)
		{
			
			throw "Invalid file";

		}
		while (!file.eof())
		{
			std::string tmp;
			std::getline(file, tmp);

			// title of the song
			size_t s_title = 25;
			temp.title = tmp.substr(0, s_title);
			temp.title.erase(0, temp.title.find_first_not_of(" "));
			temp.title.erase(temp.title.find_last_not_of(" ") + 1);

			// name of the artist
			size_t s_artist = 25;
			temp.artist = tmp.substr(s_title, s_artist);
			temp.artist.erase(0, temp.artist.find_first_not_of(" "));
			temp.artist.erase(temp.artist.find_last_not_of(" ") + 1);

			// name of the album
			size_t s_album = 25;
			temp.album = tmp.substr(s_title + s_artist, s_album);
			temp.album.erase(0, temp.album.find_first_not_of(" "));
			temp.album.erase(temp.album.find_last_not_of(" ") + 1);

			// release year
			size_t s_release = 5;
			std::string check;
			check = tmp.substr(s_title + s_artist + s_album, s_release);
			if (check == "     ")
			{
				temp.release = 0;
			}
			else
			{
				temp.release = stoi(check);
			}
			size_t s_size = 5;
			temp.size = stoi(tmp.substr(s_title + s_artist + s_album + s_release, s_size));

			size_t s_price = 5;
			temp.price = stod(tmp.substr(s_title + s_artist + s_album + s_release + s_size, s_price));

			songs.push_back(temp);
		}
	}
	void SongCollection::display(std::ostream& out) const
	{
		for (auto i = songs.begin(); i != songs.end(); i++)
		{
			out << *i;
		}
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| " << left << setw(20) << theSong.title
			<< " | " << setw(15) << theSong.artist
			<< " | " << setw(20) << theSong.album;
		if (theSong.release == 0)
		{
			out << " | " << right << setw(6) << " ";
		}
		else
		{
			out << " | " << right << setw(6) << theSong.release;
		}
		out << " | " << theSong.size / 60 << ":";
		if (theSong.size % 60 < 10)
		{
			out << '0' << theSong.size % 60;
		}
		else
		{
			out << theSong.size % 60;

		}
		out << " | " << fixed<<setprecision(2)<< theSong.price << " |" << endl;
		return out;
	}

}