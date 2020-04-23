// Name:Luciana Gonzaga Altermann
// Seneca Student ID:129855185
// Seneca email:lgonzaga-altermann
// Date of completion: 02/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_COLLETION_H
#define SDDS_COLLETION_H
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace sdds
{
	template<typename T >
	class Collection
	{
	private:
		string c_name;
		size_t c_size;
		T* c_item;
		void (*c_observer)(const Collection<T>&, const T& b);

	public:
		// constructor to save the name
		Collection(std::string name) 
		{
			c_name = name;
			c_size = 0;
			c_item = nullptr;
			c_observer = nullptr;
		}
		// desctructor 
		~Collection() 
		{
			delete[] c_item;
		}
		// query to retorn the name of collection
		const std::string& name() const 
		{
			return c_name;
		}
		// query the size of collection
		size_t size() const
		{
			return c_size;
		}
		void setObserver(void (*observer)(const Collection<T>& a, const T& b)) 
		{
			c_observer = observer;
		}
		Collection<T>& operator+=(const T& item) 
		{
			bool valid = true;
			for (size_t i = 0; i < c_size && valid; i++) 
			{
				if (c_item[i].title() == item.title())
				{
					valid = false;
				}
			}
			if (valid)
			{
				T* temp = new T[c_size + 1];
				for (size_t i = 0; i < c_size; i++)
				{
					temp[i] = c_item[i];
				}

				delete[] c_item;
				c_item = temp;
				c_item[c_size++] = item;

				if (c_observer != nullptr)
				{
					c_observer(*this, item);
				}

			}return *this;
		}
		T& operator[](size_t idx) const
		{
			if (idx < c_size)
			{
				return c_item[idx];
			}
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.");
		}
		T* operator[](std::string title) const
		{
			for (size_t i = 0; i < c_size; i++)
			{
				if (title == c_item[i].title())
				{
					return c_item + i;
				}
			}
			return nullptr;
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& c_obj)
	{
		for (size_t i = 0; i < c_obj.size(); i++) 
		{
			os << c_obj[i];
		}
		return os;
	}
}
#endif

