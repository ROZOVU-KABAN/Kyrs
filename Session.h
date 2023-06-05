#pragma once
#include <iostream>
#include "Subject.h"

class Session
{
public:
	Session();
	Session(Subject sub[]);
	~Session();

	void Set_Session(Subject sub[]);
	void Set_Session(Session ses);

	void Get_AllSub(Subject sub[]);
	Subject Get_Sub(int subNum) { return subject[subNum]; };

private:
	Subject subject[10];
};

Session::Session()
{
	for (int i = 0; i < 10; i++)
	{
		subject[i].Set_All((char*)"-", '-');
	}
}

Session::Session(Subject sub[])
{
	Set_Session(sub);
}

void Session::Set_Session(Subject sub[])
{
	for (int i = 0; i < 10; i++)
	{
		subject[i].Set_Mark(sub[i].Get_Mark());
		subject[i].Set_SubName(sub[i].Get_SubName());
	}
}

Session::~Session()
{
}

void Session::Set_Session(Session ses)
{
	for (int i = 0; i < 10; i++)
	{
		subject[i].Set_Mark(ses.Get_Sub(i).Get_Mark());
		subject[i].Set_SubName(ses.Get_Sub(i).Get_SubName());
	}
}

void Session::Get_AllSub(Subject sub[])
{
	for (int i = 0; i < 10; i++)
	{
		sub[i].Set_Mark(subject[i].Get_Mark());
		sub[i].Set_SubName(subject[i].Get_SubName());
	}
}
