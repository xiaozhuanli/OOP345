// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// 2019/01/10 - Chris Szalwinski
// 2019/09/13 - Cornel
// 2020/01/14 - Cornel
////////////////////////////////////////////////////////////////
// Workshop 2 - Copy and Move Semantics
// w2_lab.cpp
// Name: Luciana Gonzaga Altermann
// Seneca Student ID: 129855185
/* Seneca email: lgonzaga-altermann@myseneca.ca*/
// Date of completion: 01/19/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{
	
	// start timer
	void TimedEvents::startClock()
	{
		ts = std::chrono::steady_clock::now();
	}

	// stop timer
	//
	void TimedEvents::stopClock()
	{
		te = std::chrono::steady_clock::now();
	}

	// record an event
	//
	void TimedEvents::recordEvent(const char* msg)
	{
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(te - ts);
		if (nr < MAXRECORDS)
		{
			this->events[nr].msg = msg;
			this->events[nr].units = "nanoseconds";
			this->events[nr].duration = ms;
			nr++;
		}
	}

	// report the set of times recorded
	// 
	std::ostream& operator<<(std::ostream& out, const TimedEvents& events)
	{
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";
		for (int i = 0; i < events.nr; i++)
			out << std::setw(20) << std::left
			<< events.events[i].msg << ' ' << std::setw(12) << std::right
			<< events.events[i].duration.count() << ' '
			<< events.events[i].units << '\n';
		out << "--------------------------\n";
		return out;
	}

}

