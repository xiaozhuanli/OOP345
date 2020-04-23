Reservation::Reservation(const std::string& m_res)
	{
		std::string local_str = m_res;

		// remove all white spaces
		for(unsigned int i = 0; i < local_str.size(); ++i) {
			if (local_str[i] == ' ') {
				local_str.erase(i, 1);
				i = 0;
			}
		}

		//retrieve all information about the current reservation
		for (unsigned int init_position = 0, info_length = 0, count = 0, i = 0; i < local_str.size(); ++i)
		{
			if (local_str[i] == ':')
			{
				m_reservID = local_str.substr(init_position, i);
				nextInfo(count, init_position, i);
			}
			else if (local_str[i] == ',')
			{
				switch (count) {
				case 1:
					getLength(info_length, init_position, i);
					m_name = retrieveInfo(local_str, init_position, info_length);
					nextInfo(count, init_position, i);
					break;
				case 2:
					getLength(info_length, init_position, i);
					m_email = retrieveInfo(local_str, init_position, info_length);
					nextInfo(count, init_position, i);
					break;
				case 3:
					getLength(info_length, init_position, i);
					m_numOfPeople = std::stoi(retrieveInfo(local_str, init_position, info_length));
					nextInfo(count, init_position, i);
					break;
				case 4:
					getLength(info_length, init_position, i);
					m_dayReserv = std::stoi(retrieveInfo(local_str, init_position, info_length));
					nextInfo(count, init_position, i);

					info_length = (local_str.size() + 1) - init_position;
					m_timeReserv = std::stoi(retrieveInfo(local_str, init_position, info_length));
					break;
				}
			}
		}
	}

	std::string Reservation::retrieveInfo(const std::string& local_str, const unsigned int& init_position, const unsigned int& info_length)
	{
		return local_str.substr(init_position, info_length);
	}

	void Reservation::nextInfo(unsigned int& count, unsigned int& init_position, unsigned int i)
	{
		count++;
		init_position = i + 1;
	}
	void Reservation::getLength(unsigned int& info_length, unsigned int& init_position, unsigned int i)
	{
		info_length = i - init_position;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& source)
	{
		os << "Reservation " << source.m_reservID << ":" << std::setw(10) << std::right << source.m_name << " "
			<< std::setw(20) << std::left << "<" + source.m_email + ">";

		if (source.m_timeReserv >= 6 && source.m_timeReserv <= 9) {
			os << " Breakfast ";
		}
		else if(source.m_timeReserv >= 11 && source.m_timeReserv <= 13){
			os << " Lunch ";
		}
		else if (source.m_timeReserv >= 17 && source.m_timeReserv <= 19) {
			os << " Dinner ";
		}
		else {
			os << " Drinks ";
		}
		os << "on day " << source.m_dayReserv << " @ " << source.m_timeReserv
			<< ":00 for " << source.m_numOfPeople << " people." << std::endl;

		return os;
	}