#pragma once
#include<iostream>

class Subject
{
public:
	Subject();
	Subject(char name[],char mark);
	~Subject();

	char* Get_SubName() { return name; }
	char Get_Mark() { return mark; }
	
	void Set_SubName(char name[]);
	void Set_Mark(char mark);
	void Set_All(char name[], char mark);

private:

	char name[30] = {};
	char mark;

};

Subject::Subject()
{
	mark = '-';
}

inline Subject::Subject(char name[], char mark)
{
	Set_SubName(name);
	Set_Mark(mark);
}

Subject::~Subject()
{
}

inline void Subject::Set_SubName(char name[])
{
	strncpy_s(this->name, name, 30);
}

inline void Subject::Set_Mark(char mark)
{
	this->mark = mark;
}

inline void Subject::Set_All(char name[], char mark)
{
	Set_Mark(mark);
	Set_SubName(name);
}


