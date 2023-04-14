#pragma once
#include <iostream>
#include <fstream>
#include "Libruaries.h"
#include "Session.h"
#include "My_List.h"
class Student
{
public:

	Student();
	void Set_info(char dep[], char fac[], char gr[], char num[], char fn[], char sn[], char tn[], int ey, char fl[], Burn& Data, Session ses[]);
	void Set_info(Student* stud);
	void Set_Dep(char dep[]);
	void Set_Fac(char fac[]);
	void Set_Gr(char gr[]);
	void Set_Num(char num[]);
	void Set_FN(char fn[]);
	void Set_Sn(char sn[]);
	void Set_TN(char tn[]);
	void Set_Flor(char fl[]);
	void Set_EnterYear(int ey);
	void Set_Data(Burn& data);
	void Set_Ses(Session ses[]);

	void WriteInfoIntoFile(const char FileName[]);
	void ReadInfoFormFile(char number[], const char FielName[]);
	void ReadInfoFormFile(char fn[],char sn[], const char FielName[]);
	void ChangeInfoName(const char FielName[]);
	void ChangeInfoNum(const char FielName[]);
	void DeleteStudent(const char FielName[]);
	void ReadAllStud(List<Student>& l,const char FielName[]);

	Student* Get_info();
	char* Get_Dep() { return department; }
	char* Get_Fac() { return faculty; }
	char* Get_Gr() { return group; }
	char* Get_Num() { return number; }
	char* Get_FN() { return first_name; }
	char* Get_SN() { return second_name; }
	char* Get_TN() { return thired_name; }
	char* Get_Flor() { return flor; }
	int Get_EnterYear() { return enter_year; }
	void Get_Data(Burn& data) { Data.Get_Data(data); }
	void Get_Ses(Session ses[]);

	~Student();
	
private:
	char department[20] = {};
	char faculty[40] = {};
	char group[10] = {};
	char number[20] = {};
	char first_name[30] = {};
	char second_name[30] = {};
	char thired_name[30] = {};
	
	unsigned int enter_year;
	char flor[10] = {};

	
	Burn Data;
	Session session[9]; 
};

inline Student::Student()
{
	enter_year = 0;
}

inline void Student::Set_info(char dep[], char fac[], char gr[], char num[], char fn[], char sn[],char tn[], int ey, char fl[], Burn& Data, Session ses[])
{
	strncpy_s(department, dep, 20);
	strncpy_s(faculty, fac, 40);
	strncpy_s(group, gr, 10);
	strncpy_s(number, num, 20);
	strncpy_s(first_name, fn, 30);
	strncpy_s(second_name, sn, 30);
	strncpy_s(thired_name, tn, 30);
	strncpy_s(flor, fl, 10);
	enter_year = ey;
	this->Data.Set_Data(Data);
	
	for (int i = 0; i < 9; i++)
	{
		session[i].Set_Session(ses[i]);
	}
}

inline void Student::Set_info(Student* stud)
{
	strncpy_s(department, stud->department, 20);
	strncpy_s(faculty,stud->faculty,40);
	strncpy_s(first_name,stud->first_name,30);
	strncpy_s(second_name, stud->second_name, 30);
	strncpy_s(thired_name,stud->thired_name,30);
	strncpy_s(group, stud->group, 10);
	strncpy_s(number, stud->number, 20);
	strncpy_s(flor,stud->flor,10);
	enter_year = enter_year;
	for (int i = 0; i < 10; i++)
	{
		session[i].Set_Session(stud->session[i]);
	}
	stud->Data.Get_Data(Data);
}

inline void Student::Set_Dep(char dep[])
{
	strncpy_s(department, dep, 20);
}

inline void Student::Set_Fac(char fac[])
{
	strncpy_s(faculty, fac, 40);
}

inline void Student::Set_Gr(char gr[])
{
	strncpy_s(group, gr, 10);
}

inline void Student::Set_Num(char num[])
{
	strncpy_s(number, num, 20); 
}

inline void Student::Set_FN(char fn[])
{
	strncpy_s(first_name, fn, 30);
}

inline void Student::Set_Sn(char sn[])
{
	strncpy_s(second_name, sn, 30);
}

inline void Student::Set_TN(char tn[])
{
	strncpy_s(thired_name, tn, 30);
}

inline void Student::Set_Flor(char fl[])
{
	strncpy_s(flor, fl, 10);
}

inline void Student::Set_EnterYear(int ey)
{
	enter_year = ey;
}

inline void Student::Set_Data(Burn& data)
{
	this->Data.Set_Data(data);
}

inline void Student::Set_Ses(Session ses[])
{
		for (int i = 0; i < 9; i++)
	{
		session[i].Set_Session(ses[i]);
	}
}

inline void Student::WriteInfoIntoFile(const char FileName[])
{
	std::ofstream fout;
	fout.open(FileName, std::ios_base::app | std::ios_base::binary);

	fout.write((char*)&department, 20);
	fout.write((char*)&faculty, 40);
	fout.write((char*)&group, 10);
	fout.write((char*)&number, 20);
	fout.write((char*)&first_name, 30);
	fout.write((char*)&second_name, 30);
	fout.write((char*)&thired_name, 30);
	fout.write((char*)&enter_year, sizeof(unsigned int));
	fout.write((char*)&flor, 10);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Subject sub = session[i].Get_Sub(j);
			char* ch = sub.Get_SubName();
			char CH[30];
			strncpy_s(CH, ch, 30);
			char c = sub.Get_Mark();
			fout.write((char*)&CH, 30);
			fout.write((char*)&c, sizeof(char));
		}
	}
	int day = Data.Get_Day();
	int month = Data.Get_Month();
	int year = Data.Get_Year();
	fout.write((char*)&day, sizeof(int));
	fout.write((char*)&month, sizeof(int));
	fout.write((char*)&year, sizeof(int));

	fout.close();
}

inline void Student::ReadInfoFormFile(char number[], const char FielName[])
{
	std::ifstream fin;
	fin.open(FielName, std::ios_base::binary);
	if (!fin.is_open())
	{
		std::cout << "OpenError" << std::endl;
	}
	else
	{
		do
		{
			fin.read((char*)&department, 20);
			fin.read((char*)&faculty, 40);
			fin.read((char*)&group, 10);
			fin.read((char*)&(this->number), 20);
			fin.read((char*)&first_name, 30);
			fin.read((char*)&second_name, 30);
			fin.read((char*)&thired_name, 30);
			fin.read((char*)&enter_year, sizeof(unsigned int));
			fin.read((char*)&flor, 10);
			for (int i = 0; i < 9; i++)
			{
				Subject sub[10];
				for (int j = 0; j < 10; j++)
				{
					char ch[30];
					char c;
					fin.read((char*)&ch, 30);
					fin.read((char*)&c, sizeof(char));
					sub[j].Set_All(ch, c);
				}
				session[i].Set_Session(sub);
			}

			int day, month, year;
			fin.read((char*)&day, sizeof(int));
			fin.read((char*)&month, sizeof(int));
			fin.read((char*)&year, sizeof(int));
			Data.Set_Data(day, month, year);

		} while (strcmp(this->number, number));
	}
	fin.close();
}

inline void Student::ReadInfoFormFile(char fn[], char sn[], const char FielName[])
{
	std::ifstream fin;
	fin.open(FielName,std::ios_base::binary);
	if (!fin.is_open())
	{
		std::cout << "OpenError" << std::endl;
	}
	else
	{
		do
		{
			fin.read((char*)&department, 20);
			fin.read((char*)&faculty, 40);
			fin.read((char*)&group, 10);
			fin.read((char*)&number, 20);
			fin.read((char*)&first_name, 30);
			fin.read((char*)&second_name, 30);
			fin.read((char*)&thired_name, 30);
			fin.read((char*)&enter_year, sizeof(unsigned int));
			fin.read((char*)&flor, 10);
			for (int i = 0; i < 9; i++)
			{
				Subject sub[10];
				for (int j = 0; j < 10; i++)
				{
					char* ch;
					char c;
					fin.read((char*)&ch, 30);
					fin.read((char*)&c, sizeof(char));
					sub[j].Set_All(ch, c);
				}
				session[i].Set_Session(sub);
			}

			int day, month, year;
			fin.read((char*)&day, sizeof(int));
			fin.read((char*)&month, sizeof(int));
			fin.read((char*)&year, sizeof(int));
			Data.Set_Data(day, month, year);

		} while (strcmp(second_name,sn) || strcmp(first_name,fn));
	}
	fin.close();
}

inline void Student::ChangeInfoName(const char FielName[])
{
	Student stud;
	std::fstream fin;
	fin.open(FielName, std::ios_base::binary | std::ios_base::in | std::ios_base::out);
	fin.seekp(0, std::ios_base::beg);
	if (!fin.is_open())
	{
		std::cout << "OpenError" << std::endl;
	}
	else
	{
		do
		{
			fin.read((char*)&stud.department, 20);
			fin.read((char*)&stud.faculty, 40);
			fin.read((char*)&stud.group, 10);
			fin.read((char*)&stud.number, 20);
			fin.read((char*)&stud.first_name, 30);
			fin.read((char*)&stud.second_name, 30);
			fin.read((char*)&stud.thired_name, 30);
			fin.read((char*)&stud.enter_year, sizeof(unsigned int));
			fin.read((char*)&stud.flor, 10);
			
			for (int i = 0; i < 9; i++)
			{
				Subject sub[10];
				for (int j = 0; j < 10; j++)
				{
					char ch[30];
					char c;
					fin.read((char*)&ch, 30);
					fin.read((char*)&c, sizeof(char));
					sub[j].Set_All(ch, c);
				}
				stud.session[i].Set_Session(sub);
			}

			int day, month, year;
			fin.read((char*)&day, sizeof(int));
			fin.read((char*)&month, sizeof(int));
			fin.read((char*)&year, sizeof(int));
			stud.Data.Set_Data(day, month, year);
		} while (strcmp(stud.first_name, first_name) || strcmp(stud.second_name, second_name));

		fin.seekp(-2996, std::ios_base::cur);
				
		fin.write((char*)&department, 20);
		fin.write((char*)&faculty, 40);
		fin.write((char*)&group, 10);
		fin.write((char*)&number, 20);
		fin.write((char*)&first_name, 30);
		fin.write((char*)&second_name, 30);
		fin.write((char*)&thired_name, 30);
		fin.write((char*)&enter_year, sizeof(unsigned int));
		fin.write((char*)&flor, 10);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 10;j++)
			{
				Subject sub = session[i].Get_Sub(j);
				char* ch = sub.Get_SubName();
				char CH[30];
				strncpy_s(CH, ch, 30);
				char c = sub.Get_Mark();
				fin.write((char*)&CH, 30);
				fin.write((char*)&c, sizeof(char));
			}
		}
		int day = Data.Get_Day();
		int month = Data.Get_Month();
		int year = Data.Get_Year();
		fin.write((char*)&day, sizeof(int));
		fin.write((char*)&month, sizeof(int));
		fin.write((char*)&year, sizeof(int));

	}
}

inline void Student::ChangeInfoNum(const char FielName[])
{
	int numSubinOneSes;
	Student stud;
	std::fstream fin;
	fin.open(FielName, std::ios_base::binary | std::ios_base::in | std::ios_base::out);
	fin.seekp(0, std::ios_base::beg);
	if (!fin.is_open())
	{
		std::cout << "OpenError" << std::endl;
	}
	else
	{
		do
		{
			fin.read((char*)&stud.department, 20);
			fin.read((char*)&stud.faculty, 40);
			fin.read((char*)&stud.group, 10);
			fin.read((char*)&stud.number, 20);
			fin.read((char*)&stud.first_name, 30);
			fin.read((char*)&stud.second_name, 30);
			fin.read((char*)&stud.thired_name, 30);
			fin.read((char*)&stud.enter_year, sizeof(unsigned int));
			fin.read((char*)&stud.flor, 10);
			for (int i = 0; i < 9; i++)
			{
				Subject sub [10];
				for (int j = 0; j <10; j++)
				{
					char ch[30];
					char c;
					fin.read((char*)&ch, 30);
					fin.read((char*)&c, sizeof(char));
					sub[j].Set_All(ch, c);
				}
				stud.session[i].Set_Session(sub);
			}

			int day, month, year;
			fin.read((char*)&day, sizeof(int));
			fin.read((char*)&month, sizeof(int));
			fin.read((char*)&year, sizeof(int));
			stud.Data.Set_Data(day, month, year);

		} while (strcmp(stud.number, number));

		fin.seekp(-2996, std::ios_base::cur);

		fin.write((char*)&department, 20);
		fin.write((char*)&faculty, 40);
		fin.write((char*)&group, 10);
		fin.write((char*)&number, 20);
		fin.write((char*)&first_name, 30);
		fin.write((char*)&second_name, 30);
		fin.write((char*)&thired_name, 30);
		fin.write((char*)&enter_year, sizeof(unsigned int));
		fin.write((char*)&flor, 10);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 10;j++)
			{
				Subject sub = session[i].Get_Sub(j);
				char* ch = sub.Get_SubName();
				char CH[30];
				strncpy_s(CH, ch, 30);
				char c = sub.Get_Mark();
				fin.write((char*)&CH, 30);
				fin.write((char*)&c, sizeof(char));
			}
		}
		int day = Data.Get_Day();
		int month =Data.Get_Month();
		int year = Data.Get_Year();
		fin.write((char*)&day, sizeof(int));
		fin.write((char*)&month, sizeof(int));
		fin.write((char*)&year, sizeof(int));
	}
	fin.close();
}

inline void Student::DeleteStudent(const char FielName[])
{
	Student stud;
	std::ofstream fout;
	std::ifstream fin;
	char fiel[] = "FIEL.txt";
	fout.open(fiel, std::ios_base::binary);
	fin.open(FielName, std::ios_base::binary);
	if(!fin.is_open())
	{
		std::cout << "Error open file" << std::endl;
		return;
	}
	else
	{
		if (!fout.is_open())
		{
			std::cout << "Error open file" << std::endl;
			return;
		}
		else
		{
			while (!fin.eof())
			{
				fin.read((char*)&stud.department, 20);
				fin.read((char*)&stud.faculty, 40);
				fin.read((char*)&stud.group, 10);
				fin.read((char*)&stud.number, 20);
				fin.read((char*)&stud.first_name, 30);
				fin.read((char*)&stud.second_name, 30);
				fin.read((char*)&stud.thired_name, 30);
				fin.read((char*)&stud.enter_year, sizeof(unsigned int));
				fin.read((char*)&stud.flor, 10);
				for (int i = 0; i < 9; i++)
				{
					Subject sub[10];
					for (int j = 0; j < 10; j++)
					{
						char ch[30];
						char c;
						fin.read((char*)&ch, 30);
						fin.read((char*)&c, sizeof(char));
						sub[j].Set_All(ch, c);
					}
					stud.session[i].Set_Session(sub);
				}

				int day, month, year;
				fin.read((char*)&day, sizeof(int));
				fin.read((char*)&month, sizeof(int));
				fin.read((char*)&year, sizeof(int));
				stud.Data.Set_Data(day, month, year);
				if (stud.number != number)
				{
					fout.write((char*)&department, 20);
					fout.write((char*)&faculty, 40);
					fout.write((char*)&group, 10);
					fout.write((char*)&number, 20);
					fout.write((char*)&first_name, 30);
					fout.write((char*)&second_name, 30);
					fout.write((char*)&thired_name, 30);
					fout.write((char*)&enter_year, sizeof(unsigned int));
					fout.write((char*)&flor, 10);
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Subject sub = session[i].Get_Sub(j);
							char* ch = sub.Get_SubName();
							char CH[30];
							strncpy_s(CH, ch, 30);
							char c = sub.Get_Mark();
							fout.write((char*)&CH, 30);
							fout.write((char*)&c, sizeof(char));
						}
					}
					int day = Data.Get_Day();
					int month = Data.Get_Month();
					int year = Data.Get_Year();
					fout.write((char*)&day, sizeof(int));
					fout.write((char*)&month, sizeof(int));
					fout.write((char*)&year, sizeof(int));
				}
			}
		}
	}
	fin.close();
	remove(FielName);
	rename(fiel, FielName);
	fout.close();
}

inline void Student::ReadAllStud(List<Student>& l, const char FielName[])
{
	Student stud;
	std::ifstream fin;
	fin.open(FielName, std::ios_base::binary);
	while (!fin.eof())
	{
		fin.read((char*)&stud.department, 20);
		fin.read((char*)&stud.faculty, 40);
		fin.read((char*)&stud.group, 10);
		fin.read((char*)&stud.number, 20);
		fin.read((char*)&stud.first_name, 30);
		fin.read((char*)&stud.second_name, 30);
		fin.read((char*)&stud.thired_name, 30);
		fin.read((char*)&stud.enter_year, sizeof(unsigned int));
		fin.read((char*)&stud.flor, 10);
		for (int i = 0; i < 9; i++)
		{
			Subject sub[10];
			for (int j = 0; j < 10; j++)
			{
				char ch[30];
				char c;
				fin.read((char*)&ch, 30);
				fin.read((char*)&c, sizeof(char));
				sub[j].Set_All(ch, c);
			}
			stud.session[i].Set_Session(sub);
		}

		int day, month, year;
		fin.read((char*)&day, sizeof(int));
		fin.read((char*)&month, sizeof(int));
		fin.read((char*)&year, sizeof(int));
		stud.Data.Set_Data(day, month, year);
		l.push_back(stud);
	}
}

inline Student* Student::Get_info()
{
	Student stud;
	stud.Data.Get_Data(Data);
	strncpy_s(stud.department, department, 20);
	strncpy_s(stud.faculty, faculty, 40);
	strncpy_s(stud.first_name, first_name, 30);
	strncpy_s(stud.second_name, second_name, 30);
	strncpy_s(stud.thired_name, thired_name, 30);
	strncpy_s(stud.group, group, 10);
	strncpy_s(stud.number, number, 20);
	strncpy_s(stud.flor, flor, 10);
	
	stud.enter_year = enter_year;
	
	stud.Get_Ses(session);
	
	return &stud;
}

inline void Student::Get_Ses(Session ses[])
{
	for (int i = 0; i < 9; i++)
	{
		ses[i].Set_Session(session[i]);
	}
}

inline Student::~Student()
{
}