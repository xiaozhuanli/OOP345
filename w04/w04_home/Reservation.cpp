// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 01/05/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds
{
	// initialization of variables.?

	Reservation::Reservation()
	{
		reservation_id = "";
		r_name = "";
		r_email = "";
		r_people = 0;
		party_date = 0;
		party_hour = 0;
	}
	Reservation::Reservation(const string& r_res)
	{

			string temp = r_res;  
			size_t count = 0;
			// finding the white spaces
			while (temp.find(" ") != std::string::npos) 
			{
				count = temp.find(" ");
				temp.erase(count, 1);
			}
			// Reservation ID
			count = temp.find(":");
			reservation_id = temp.substr(0, count);
			temp.erase(0, count + 1);

			// name on the reservation
			count = temp.find(",");
			r_name = temp.substr(0, count);
			temp.erase(0, count + 1);

			// email of reservation
			count = temp.find(",");
			r_email = '<' + temp.substr(0, count) + '>';
			temp.erase(0, count + 1);

			// number of people on the party
			count = temp.find(",");
			r_people = stoi(temp);
			temp.erase(0, count + 1);

			//reservation date party
			count = temp.find(",");
			party_date = stoi(temp);
			temp.erase(0, count + 1);

			// reservation hour
			party_hour = stoi(temp);
		
			
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& obj)
	{
		string temp;
		if (obj.party_hour >= 6 && obj.party_hour <= 9)
			temp = "Breakfast on day";
		else if (obj.party_hour >= 11 && obj.party_hour <= 15)
			temp = "Lunch on day";
		else if (obj.party_hour >= 17 && obj.party_hour <= 21)
			temp = "Dinner on day";
		else
			temp = "Drinks on day";
		os << "Reservation " << obj.reservation_id << ":" <<setw(11) << right << obj.r_name
			<< "  " << setw(24) << left << obj.r_email << temp << " " << obj.party_date
			<< " @ " << obj.party_hour << ":00 for " << obj.r_people << " people." << endl;
		return os;
	}
}
// This one was building to lab part but I remove due to the fact that I did not knew 
			// that I could not used algorithm library to build my code.  
		//// Reservation ID
		//int r_id = r_res.find(':');
		//reservation_id = r_res.substr(0, r_id);
		//reservation_id.erase(remove(reservation_id.begin(), reservation_id.end(), ' '), reservation_id.end());
		//// name on the reservation
		//int name = r_res.find(',');
		//r_name = r_res.substr(r_id + 1, name - r_id - 1);
		//r_name.erase(remove(r_name.begin(), r_name.end(), ' '), r_name.end());
		//// email of reservation
		//int email = r_res.find(',', name + 1);
		//r_email.insert(0, "<");
		//r_email.append(r_res.substr(name + 1, email - name - 1));
		//r_email.erase(remove(r_email.begin(), r_email.end(), ' '), r_email.end());
		//r_email.append(">");
		//// number of people on the party
		//int people = r_res.find(',', email + 1);
		//r_people = stoi(r_res.substr(email + 1, people - email - 1));
		////reservation date party
		//int date = r_res.find(',', people + 1);
		//party_date = stoi(r_res.substr(people + 1, date - people - 1));
		//// reservation hour
		//int hour = r_res.length();
		//party_hour = stoi(r_res.substr(date + 1, hour - date - 1));