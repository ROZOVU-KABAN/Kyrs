#include <iostream>
#include "Libruaries.h"
#include <fstream>
#include <windows.h>
//48-57
const char FielName[] = "File.txt";

bool ChekChar(char ch[])
{
	for (int i = 0; i < 40; i++)
	{
		if (int(ch[i]) > 47 && int(ch[i]) < 58)
			return false;
	}
	return true;
}

void Set_Session(Student& stud)
{
	system("cls");
	Session ses[9];
	Subject sub[10];
	int nSes;
	int nSub;
	char name[30];
	char ch;
	std::cout << "Введите количество сессий: ";
	std::cin >> nSes; std::cout << std::endl;
	for (int i = 0; i < nSes; i++)
	{
		std::cout << "Введите количество предметов в  "<< i <<"-ой сесиии: ";
		std::cin >> nSub; std::cout << std::endl;
		for (int j = 0; j < nSub; j++)
		{
			std::cout << "Введите название предмета: "; std::cin >> name; std::cout << std::endl;
			std::cout << "Введите оценку: "; std::cin >> ch; std::cout << std::endl;
			sub[j].Set_All(name, ch);
		}
		ses[i].Set_Session(sub);
		system("cls");
	}
	stud.Set_Ses(ses);
}

void ChangeInfo(Student& stud)
{
	system("cls");
	int flag;
	int num;
	int day, month, year;
	char ch[40] = {};
	std::cout << "1 - Отделение" << std::endl;
	std::cout << "2 - Пол" << std::endl;
	std::cout << "3 - Номер зачетной книжки" << std::endl;
	std::cout << "4 - Факультет" << std::endl;
	std::cout << "5 - Группа" << std::endl;
	std::cout << "6 - Дату рождения" << std::endl;
	std::cout << "7 - Год поступления" << std::endl;
	std::cout << "8 - Фамилия" << std::endl;
	std::cout << "9 - Имя" << std::endl;
	std::cout << "10 - Отчество" << std::endl;
	std::cout << "11 - Сессию" << std::endl;
	std::cin >> flag;
	switch (flag)
	{
	case 1:
	{
		std::cout << "Введите отделение" << std::endl;
		std::cin >> ch;
		if (ChekChar(ch))
		{
			stud.Set_Dep(ch);
			stud.ChangeInfoNum(stud.Get_Num());
		}
		else
		{
			std::cout << "error text, no 0-9" << std::endl;
		}
		break;
	}
	case 2:
	{
		std::cout << "Введите пол" << std::endl;
		std::cin >> ch;
		
		std::cin >> ch;
		if (ChekChar(ch))
		{
			stud.Set_Flor(ch);
			stud.ChangeInfoNum(FielName);
		}
		else
		{
			std::cout << "error text, no 0-9" << std::endl;
		}
		break;
	}
	case 3:
	{
		std::cout << "Введите ономер зачетной книжки" << std::endl;
		std::cin >> ch;
		stud.Set_Num(ch);
		stud.ChangeInfoName(FielName);
		break;
	}
	case 4:
	{
		std::cout << "Введите факультет" << std::endl;
		std::cin >> ch;
		if (ChekChar(ch))
		{
			stud.Set_Fac(ch);
			stud.ChangeInfoName(FielName);
		}
		else
		{
			std::cout << "error text, no 0-9" << std::endl;
		}

		break;
	}
	case 5:
	{
		std::cout << "Введите группу" << std::endl;
		std::cin >> ch;
		stud.Set_Dep(ch);
		stud.ChangeInfoName(FielName);
		break;
	}
	case 6:
	{
		std::cout << "Введите день" << std::endl;
		std::cin >> day;
		std::cout << "Введите месяц" << std::endl;
		std::cin >> month;
		std::cout << "Введите год" << std::endl;
		std::cin >> year;
		Burn data(day, month, year);
		stud.Set_Data(data);
		stud.ChangeInfoName(FielName);
		break;
	}
	case 7:
	{
		std::cout << "Введите год поступления" << std::endl;
		std::cin >> num;
		stud.Set_EnterYear(num);
		stud.ChangeInfoName(FielName);
		break;
	}
	case 8:
	{
		std::cout << "Введите фамилию" << std::endl;
		std::cin >> ch;
		if (ChekChar(ch))
		{
			stud.Set_FN(ch);
			stud.ChangeInfoNum(FielName);
		}
		else
		{
			std::cout << "error text, no 0-9" << std::endl;
		}
		break;
	}
	case 9:
	{
		std::cout << "Введите имя" << std::endl;
		std::cin >> ch;
		if (ChekChar(ch))
		{
			stud.Set_Sn(ch);
			stud.ChangeInfoNum(FielName);
		}
		else
		{
			std::cout << "error text, no 0-9" << std::endl;
		}
		break;
	}
	case 10:
	{

		std::cout << "Введите отчество" << std::endl;
		std::cin >> ch;
		if (ChekChar(ch))
		{
			stud.Set_TN(ch);
			stud.ChangeInfoNum(FielName);
		}
		else
		{
			std::cout << "error text, no 0-9" << std::endl;
		}
		break;
	}
	case 11:
	{
		system("cls");
		Set_Session(stud);
		stud.ChangeInfoNum(FielName);
		break;
	}
	default:
	{
		std::cout << "error number" << std::endl;
		break;
	}
	}
}

void print_functionMain()
{
	system("cls");
	std::cout << "Введите, что хотите сделать:" << std::endl;
	std::cout << "1 - Посмотреть список всех студентов" << std::endl;
	std::cout << "2 - Найти конкретного студента" << std::endl;
	std::cout << "3 - Изменить информацию о студенте" << std::endl;
	std::cout << "4 - Удалить информацию о студенте" << std::endl;
	std::cout << "5 - Посмотреть информацию о сесии студента" << std::endl;
	std::cout << "6 - Добавить студента" << std::endl;
	std::cout << "0 - Завершить прграмму" << std::endl;
}

void DrawAllStud(List<Student>& l)
{

	system("cls");
	
	std::cout << "|"; std::cout.width(60); std::cout << "Фамалия Имя Отчество";
	std::cout << "|"; std::cout.width(15); std::cout << "Пол";
	std::cout << "|"; std::cout.width(25); std::cout << "Номер зачетки";
	std::cout << "|"; std::cout.width(25); std::cout << "Отделение";
	std::cout << "|"; std::cout.width(20); std::cout << "Факультет";
	std::cout << "|"; std::cout.width(15); std::cout << "Группа";
	std::cout << "|"; std::cout.width(5); std::cout << "Год поступления";
	std::cout << "|"; std::cout.width(18); std::cout << "Год рождения";
	std::cout << "|" << std::endl;

	for (int i = 0; i < l.Get_Size(); i++)
	{
		Burn data;
		l[i].Get_Data(data);
		std::cout << "|"; std::cout.width(20); std::cout << l[i].Get_FN();
		std::cout.width(20); std::cout << l[i].Get_SN();
		std::cout.width(20); std::cout<< l[i].Get_TN();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_Flor();
		std::cout << "|"; std::cout.width(25); std::cout << l[i].Get_Num();
		std::cout << "|"; std::cout.width(25); std::cout << l[i].Get_Dep();
		std::cout << "|"; std::cout.width(20); std::cout << l[i].Get_Fac();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_Gr();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_EnterYear();
		std::cout << "|"; std::cout.width(10); 
		if (data.Get_Day() / 10 == 0) std::cout << "0";
		std::cout << data.Get_Day()<<".";
		if (data.Get_Month() / 10 == 0) std::cout << "0";
		std::cout << data.Get_Month()<<".";
		std::cout << data.Get_Year();
		std::cout << "|"<<std::endl;
	}
	char ch1;
	std::cout<<std::endl<<std::endl << "Введите 0 чтобы вернуться назад" << std::endl;
	while (true)
	{
		std::cin >> ch1;
		if (ch1 == '0') break;
	}
}

void DrawOneStud(Student& stud)
{
	system("cls");
	std::cout << "|"; std::cout.width(60); std::cout << "Фамалия Имя Отчество";
	std::cout << "|"; std::cout.width(15); std::cout << "Пол";
	std::cout << "|"; std::cout.width(25); std::cout << "Номер зачетки";
	std::cout << "|"; std::cout.width(25); std::cout << "Отделение";
	std::cout << "|"; std::cout.width(20); std::cout << "Факультет";
	std::cout << "|"; std::cout.width(15); std::cout << "Группа";
	std::cout << "|"; std::cout.width(5); std::cout << "Год поступления";
	std::cout << "|"; std::cout.width(18); std::cout << "Год рождения";
	std::cout << "|" << std::endl;

	Burn data;
	stud.Get_Data(data);
	std::cout << "|"; std::cout.width(20); std::cout << stud.Get_FN();
	std::cout.width(20); std::cout << stud.Get_SN();
	std::cout.width(20); std::cout << stud.Get_TN();
	std::cout << "|"; std::cout.width(15); std::cout << stud.Get_Flor();
	std::cout << "|"; std::cout.width(25); std::cout << stud.Get_Num();
	std::cout << "|"; std::cout.width(25); std::cout << stud.Get_Dep();
	std::cout << "|"; std::cout.width(20); std::cout << stud.Get_Fac();
	std::cout << "|"; std::cout.width(15); std::cout << stud.Get_Gr();
	std::cout << "|"; std::cout.width(15); std::cout << stud.Get_EnterYear();
	std::cout << "|"; std::cout.width(10);
	if (data.Get_Day() / 10 == 0) std::cout << "0";
	std::cout << data.Get_Day() << ".";
	if (data.Get_Month() / 10 == 0) std::cout << "0";
	std::cout << data.Get_Month() << ".";
	std::cout << data.Get_Year();
	std::cout << "|" << std::endl;
	char ch1;
	std::cout << std::endl << std::endl << "Введите 0 чтобы вернуться назад" << std::endl;
	while (true)
	{
		std::cin >> ch1;
		if (ch1 == '0') break;
	}
}

void print_session(Student& stud)
{
	Session ses[9];
	stud.Get_Ses(ses);
	std::cout << "|"; std::cout.width(30); std::cout << "Сессии"; std::cout << "  |" << std::endl;
	for (int i = 0; i < 9; i++)
	{
		std::cout << "|"; std::cout.width(30); std::cout << "Номер сессии - "; std::cout<<i+1 <<" |" << std::endl;
		for (int j = 0; j < 10; j++)
		{
			std::cout << "|"; std::cout.width(30); std::cout << ses[i].Get_Sub(j).Get_SubName() << " " << ses[i].Get_Sub(j).Get_Mark(); std::cout << "|" << std::endl;
		}
	}
	char ch1;
	std::cout << std::endl << std::endl << "Введите 0 чтобы вернуться назад" << std::endl;
	while (true)
	{
		std::cin >> ch1;
		if (ch1 == '0') break;
	}
}

void NewStud(List<Student>& l)
{
	Student stud;
	char ch[40];
	int num, day, month, year;
	std::cout << "Введите фамилию" << std::endl;
	std::cin >> ch;
	if (ChekChar(ch))
	{
		stud.Set_FN(ch);
	}
	std::cout << "Введите имя" << std::endl;
	std::cin >> ch;
	if (ChekChar(ch))
	{
		stud.Set_Sn(ch);
	}
	std::cout << "Введите отчество" << std::endl;
	std::cin >> ch;
	if (ChekChar(ch))
	{
		stud.Set_TN(ch);
	}
	std::cout << "Введите номер зачетки" << std::endl;
	std::cin >> ch;
	stud.Set_Num(ch);
	std::cout << "Введите группу" << std::endl;
	std::cin >> ch;
	stud.Set_Gr(ch);
	std::cout << "Введите отдел" << std::endl;
	std::cin >> ch;
	stud.Set_Dep(ch);
	std::cout << "Введите пол" << std::endl;
	std::cin >> ch;
	stud.Set_Flor(ch);
	std::cout << "Введите год поступления" << std::endl;
	std::cin >> num;
	stud.Set_EnterYear(num);
	std::cout << "Введите день" << std::endl;
	std::cin >> day;
	std::cout << "Введите месяц" << std::endl;
	std::cin >> month;
	std::cout << "Введите год" << std::endl;
	std::cin >> year;
	Burn data(day, month, year);
	stud.Set_Data(data);
	Set_Session(stud);
	l.push_back(stud);
	stud.WriteInfoIntoFile(FielName);
}

int main()
{
	setlocale(LC_ALL, "ru");
	List<Student> l;
	Student stud;
	stud.ReadAllStud(l, FielName);
	Burn data;
	Subject sub[10];
	Session ses[9];
	int flag = 1;

	stud.ReadAllStud(l, FielName);

	while (flag)
	{
		do
		{
			print_functionMain();
			std::cin >> flag;
		} while (flag>6 || flag <0);
		
		switch (flag)
		{
		case 1:
		{
			DrawAllStud(l);
		}
		case 2:
		{
			system("cls");
			std::cout << "Введите номер зачетки студента: ";
			char numb[20] = {};
			for (int i = 0; i < l.Get_Size(); i++)
			{
				if (!strcmp(numb, l[i].Get_Num()))
				{
					DrawOneStud(l[i]);
					break;
				}
			}
			break;
		}
		case 3:
		{
			std::cout << "Введите номер зачетки студента: ";
			char numb[20] = {};
			for (int i = 0; i < l.Get_Size(); i++)
			{
				if (!strcmp(numb, l[i].Get_Num()))
				{
					ChangeInfo(l[i]);
					break;
				}
			}
			break;
		}
		case 4:
		{
			std::cout << "Введите номер зачетки студента: ";
			char numb[20] = {};
			for (int i = 0; i < l.Get_Size(); i++)
			{
				if (!strcmp(numb, l[i].Get_Num())) l[i].DeleteStudent(FielName);
			}
		}
		case 5:
		{
			system("cls");
			std::cout << "Введите номер зачетки студента: ";
			char numb[20] = {};
			std::cin >> numb;
			for (int i = 0; i < l.Get_Size(); i++)
			{
				if (!strcmp(numb, l[i].Get_Num()))
				{
					print_session(l[i]);
					break;
				}
			}
			break;
		}
		case 6:
		{
			NewStud(l);
		}
		default:
		{
			std::cout << "error number" <<std::endl;
			break;
		}

		}
		if (!flag) break;
	}
	
	return 0;
}