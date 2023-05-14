#pragma once
#include <iostream>


class Burn
{
public:
	Burn();
	Burn(int day,int month,int year);
	void Set_Data(int day, int month, int year);
	void Set_Data(Burn& data);

	void Get_Data(Burn& data);
	int Get_Day() { return day; }
	int Get_Month() { return month; }
	int Get_Year() { return year; }
	void Get_Data(int& day, int& month, int& year);

	void Change_Day(int new_day);
	void Change_Month(int new_month);
	void Change_Year(int new_year);
	~Burn();



private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

Burn::Burn()
{
	day = 0;
	month = 0;
	year = 0;
}

inline Burn::Burn(int day, int month, int year)
{
	Set_Data(day, month, year);
}

inline void Burn::Set_Data(int day, int month, int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 32 && day>0)
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else
		{
			std::cout << "Error data. Pleas enter correct data"<<std::endl;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 31 && day>0)
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else
		{
			std::cout << "Error data. Pleas enter correct data" << std::endl;
		}
	}
	else if (month == 2)
	{
		if (day < 29 && day>0)
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else
		{
			std::cout << "Error data. Pleas enter correct data" << std::endl;
		}
	}
}

inline void Burn::Set_Data(Burn& data)
{
	Set_Data(data.day, data.month, data.year);
}

inline void Burn::Get_Data(Burn& data)
{
	data.day = day;
	data.month = month;
	data.year = year;
}

inline void Burn::Get_Data(int& day, int& month, int& year)
{
	day = this->day;
	month = this->month;
	year = this->year;
}

inline void Burn::Change_Day(int new_day)
{
	Set_Data(new_day, month, year);
}

inline void Burn::Change_Month(int new_month)
{
	Set_Data(day, new_month, year);
}

inline void Burn::Change_Year(int new_year)
{
	Set_Data(day, month, new_year);
}

Burn::~Burn()
{}