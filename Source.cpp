#include <iostream>
#include "Libruaries.h"
#include <fstream>
#include <windows.h>
#include <string>

//48-57
const char FielName[] = "file.txt";

bool CheckNum(char ch[]);

int CharToInt(char ch[]);

void Crypt();

void Decrypt();

bool ChekChar(char ch[]);

void Set_Session(Student& stud);

void ChangeInfo(Student& stud);

void print_functionMain();

void DrawAllStud(List<Student>& l);

void DrawOneStud(Student& stud);

void print_session(Student& stud);

void NewStud(List<Student>& l);

void IndividualTask(List<Student>& l);

void menu();

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	Decrypt();

	menu();

	Crypt();

	return 0;
}

bool CheckNum(char ch[])
{
	for (int i = 0; i < 10; i++)
	{
		if (int(ch[i]) == 0) break;
		if (int(ch[i]) < 48 || int(ch[i]) > 57) return false;
	}
	return true;
}

int CharToInt(char ch[])
{
	if (CheckNum(ch))
	{
		int num = ch[0] - '0';

		for (int i = 1; i < 10; i++)
		{
			if (int(ch[i]) == 0) break;

			num *= 10;
			num += ch[i] - '0';
		}

		return num;
	}
	else
	{
		std::cout << "Error type of data" << std::endl;
		return -1;
	}
}

void Crypt()
{
	srand(time(NULL));
	char* pass = new char[64];
	for (int i = 0; i < 64; ++i) {
		switch (rand() % 3) {
		case 0:
			pass[i] = rand() % 10 + '0';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}
	std::string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in file.txt -out file.txt.enc -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove("file.txt") != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
	std::ofstream file;
	file.open("key.txt", std::ios_base::binary);
	file.write(pass, 65);
	file.close();
	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());
	if (remove("key.txt") != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
}

void Decrypt()
{
	std::string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
	system(command.c_str());
	if (remove("key.txt.enc") != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
	char* pass = new char[64];
	std::ifstream file;
	file.open("key.txt", std::ios_base::binary);
	file.read(pass, 65);
	file.close();
	if (remove("key.txt") != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in file.txt.enc -out file.txt -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove("file.txt.enc") != 0) {
		std::cout << "[ERROR] - deleting file" << std::endl;
	}
}

bool ChekChar(char ch[])
{
	if (int(ch[0]) < -64 || int(ch[0]) > -33) return false;
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
	int nSes;
	int nSub;
	char ch[40];

	do
	{
		std::cout << "Введите количество сессий: ";
		std::cin >> ch; std::cout << std::endl;
		nSes = CharToInt(ch);
	} while (!CharToInt(ch));

	Session ses[9];
	std::cout << "!Внимание! Если предмет оценивается зачетом, то зачет - оценка 1, не зачем - оценка 0" << std::endl;
	for (int i = 0; i < nSes; i++)
	{
		do
		{
			std::cout << "Введите количество предметов в  " << i + 1 << "-ой сесиии: ";
			std::cin >> ch; std::cout << std::endl;
			nSub = CharToInt(ch);
		} while (!CharToInt(ch));

		Subject sub[10];

		for (int j = 0; j < nSub; j++)
		{
			char ch;
			char* name = new char[30];
			std::cout << "Введите название предмета: "; std::cin.getline(name, 30);  std::cin.getline(name, 30); std::cout << std::endl;
			std::cout << "Введите оценку: "; std::cin >> ch; std::cout << std::endl;
			sub[j].Set_All(name, ch);
			delete name;
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
		stud.Set_Dep(ch);
		stud.ChangeInfoNum(FielName);
		break;
	}
	case 2:
	{
		std::cout << "Введите пол" << std::endl;

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
		do
		{
			std::cout << "Введите день" << std::endl;
			std::cin >> ch;
			day = CharToInt(ch);
		} while (!CharToInt(ch));
		do
		{
			std::cout << "Введите месяц" << std::endl;
			std::cin >> ch;
			month = CharToInt(ch);
		} while (!CharToInt(ch));
		do
		{
			std::cout << "Введите год" << std::endl;
			std::cin >> ch;
			year = CharToInt(ch);
		} while (!CharToInt(ch));
		Burn data(day, month, year);
		stud.Set_Data(data);
		stud.ChangeInfoName(FielName);
		break;
	}
	case 7:
	{
		do
		{
			std::cout << "Введите год поступления" << std::endl;
			std::cin >> ch;
			num = CharToInt(ch);
		} while (!CharToInt(ch));
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
	std::cout << "7 - Индивидуальное задание" << std::endl;
	std::cout << "8 - Прочитать все данные из файла" << std::endl;
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
	std::cout  << std::endl;

	for (int i = 0; i < l.Get_Size() - 1; i++)
	{
		Burn data;
		l[i].Get_Data(data);
		std::cout << "|"; std::cout.width(20); std::cout << l[i].Get_FN();
		std::cout.width(20); std::cout << l[i].Get_SN();
		std::cout.width(20); std::cout << l[i].Get_TN();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_Flor();
		std::cout << "|"; std::cout.width(25); std::cout << l[i].Get_Num();
		std::cout << "|"; std::cout.width(25); std::cout << l[i].Get_Dep();
		std::cout << "|"; std::cout.width(20); std::cout << l[i].Get_Fac();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_Gr();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_EnterYear();
		std::cout << "|"; std::cout.width(10);
		if (data.Get_Day() / 10 == 0) std::cout << "0";
		std::cout << data.Get_Day() << ".";
		if (data.Get_Month() / 10 == 0) std::cout << "0";
		std::cout << data.Get_Month() << ".";
		std::cout << data.Get_Year();
		std::cout << std::endl;
	}
	char ch1;
	std::cout << std::endl << std::endl << "Введите 0 чтобы вернуться назад" << std::endl;
	while (true)
	{
		std::cin >> ch1;
		if (ch1 == '0') break;
	}
}

void DrawOneStud(Student& stud)
{
	//system("cls");
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
	std::cout << "|"; std::cout.width(40); std::cout << "Сессии" << std::endl;
	for (int i = 0; i < 9; i++)
	{
		std::cout << "|"; std::cout.width(40); std::cout << "Номер сессии -  "; std::cout << i + 1  << std::endl;
		for (int j = 0; j < 10; j++)
		{
			if (ses[i].Get_Sub(j).Get_Mark() == '0')
			{
				std::cout << "|"; std::cout.width(40); std::cout << ses[i].Get_Sub(j).Get_SubName() << " не зачет"<< std::endl;
			}
			else if (ses[i].Get_Sub(j).Get_Mark() == '1')
			{
				std::cout << "|"; std::cout.width(40); std::cout << ses[i].Get_Sub(j).Get_SubName() << " зачет" << std::endl;
			}
			else
			{
				std::cout << "|"; std::cout.width(40); std::cout << ses[i].Get_Sub(j).Get_SubName() << " " << ses[i].Get_Sub(j).Get_Mark()<< std::endl;
			}
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
	system("cls");
	Student stud;
	char ch[40];
	int num, day, month, year;
	do
	{
		memset(ch, 0, sizeof(ch));
		std::cout << "Введите фамилию" << std::endl;
		std::cin >> ch;
	} while (!ChekChar(ch));
	stud.Set_FN(ch);
	do
	{
		memset(ch, 0, sizeof(ch));
		std::cout << "Введите имя" << std::endl;
		std::cin >> ch;
	} while (!ChekChar(ch));
	stud.Set_Sn(ch);

	do
	{
		memset(ch, 0, sizeof(ch));
		std::cout << "Введите отчество" << std::endl;
		std::cin >> ch;
	} while (!ChekChar(ch));
	stud.Set_TN(ch);

	std::cout << "Введите номер зачетки" << std::endl;
	std::cin >> ch;
	stud.Set_Num(ch);
	std::cout << "Введите группу" << std::endl;
	std::cin >> ch;
	stud.Set_Gr(ch);
	std::cout << "Введите факультет" << std::endl;
	std::cin.getline(ch, 40);
	std::cin.getline(ch, 40);
	stud.Set_Fac(ch);
	std::cout << "Введите отдел" << std::endl;
	std::cin.getline(ch, 40);
	stud.Set_Dep(ch);
	std::cout << "Введите пол" << std::endl;
	std::cin >> ch;
	stud.Set_Flor(ch);

	do
	{
		std::cout << "Введите год поступления (только год)" << std::endl;
		std::cin >> ch;
		num = CharToInt(ch);
	} while (!CharToInt(ch));
	stud.Set_EnterYear(num);
	std::cout << "Введите дату рождения: " << std::endl;

	do
	{
		std::cout << "Введите день" << std::endl;
		std::cin >> ch;
		day = CharToInt(ch);
	} while (!CharToInt(ch));
	do
	{

		std::cout << "Введите месяц" << std::endl;
		std::cin >> ch;
		month = CharToInt(ch);
	} while (!CharToInt(ch));
	do
	{
		std::cout << "Введите год" << std::endl;
		std::cin >> ch;
		year = CharToInt(ch);
	} while (!CharToInt(ch));



	Burn data(day, month, year);
	stud.Set_Data(data);
	Set_Session(stud);
	l.push_back(stud);
	stud.WriteInfoIntoFile(FielName);
}

void IndividualTask(List<Student>& l)
{
	for (int i = 1; i < l.Get_Size() - 1; i++)
	{
		for (int j = i; j < l.Get_Size() - 1; j++)
		{
			if (strcmp(l[j - 1].Get_FN(), l[j].Get_FN()) > 0)
			{
				std::swap(l[j], l[j - 1]);
			}
		}
	}

	//А - -64  Я - -33
	//Р - -48
	int k = 0;
	for (int i = 1; i < l.Get_Size() - 1; i++)
	{
		if (l[i].Get_FN()[0] >= -48)
		{
			k = i;
			break;
		}

		for (int j = 1; j < l.Get_Size() - 1; j++)
		{
			if (l[j].Get_FN()[0] >= -48)
			{
				break;
			}

			if (l[j - 1].Get_Sr_Ball() > l[j].Get_Sr_Ball())
			{
				std::swap(l[j], l[j - 1]);
			}
		}
	}


	for (int i = k; i < l.Get_Size() - 1; i++)
	{
		for (int j = k + 1; j < l.Get_Size() - 1; j++)
		{
			if (l[j - 1].Get_Sr_Ball() > l[j].Get_Sr_Ball())
			{
				std::swap(l[j], l[j - 1]);
			}
		}
	}
	
	char ch[40];
	do 
	{
		std::cout << "Производить выборку по\n 1 - мужчинам\n 2 - женщинам\n";
		std::cin >> ch;
		if (ch[0] == '1' || ch[0] == '2') break;
	} while (1);



	system("cls");

	std::cout << "|"; std::cout.width(60); std::cout << "Фамалия Имя Отчество";
	std::cout << "|"; std::cout.width(15); std::cout << "Пол";
	std::cout << "|"; std::cout.width(25); std::cout << "Номер зачетки";
	std::cout << "|"; std::cout.width(25); std::cout << "Отделение";
	std::cout << "|"; std::cout.width(20); std::cout << "Факультет";
	std::cout << "|"; std::cout.width(15); std::cout << "Группа";
	std::cout << "|"; std::cout.width(5); std::cout << "Год поступления";
	std::cout << "|"; std::cout.width(18); std::cout << "Год рождения";
	std::cout << std::endl;

	char flag;
	if (ch[0] == '1') flag = 'м';
	else flag = 'ж';

	for (int i = 0; i < l.Get_Size() - 1; i++)
	{
		if (l[i].Get_Flor()[0] != flag) continue;
		Burn data;
		l[i].Get_Data(data);
		std::cout << "|"; std::cout.width(20); std::cout << l[i].Get_FN();
		std::cout.width(20); std::cout << l[i].Get_SN();
		std::cout.width(20); std::cout << l[i].Get_TN();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_Flor();
		std::cout << "|"; std::cout.width(25); std::cout << l[i].Get_Num();
		std::cout << "|"; std::cout.width(25); std::cout << l[i].Get_Dep();
		std::cout << "|"; std::cout.width(20); std::cout << l[i].Get_Fac();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_Gr();
		std::cout << "|"; std::cout.width(15); std::cout << l[i].Get_EnterYear();
		std::cout << "|"; std::cout.width(10);
		if (data.Get_Day() / 10 == 0) std::cout << "0";
		std::cout << data.Get_Day() << ".";
		if (data.Get_Month() / 10 == 0) std::cout << "0";
		std::cout << data.Get_Month() << ".";
		std::cout << data.Get_Year();
		std::cout << std::endl;
	}
	char ch1;
	std::cout << std::endl << std::endl << "Введите 0 чтобы вернуться назад" << std::endl;
	while (true)
	{
		std::cin >> ch1;
		if (ch1 == '0') break;
	}


}

void menu()
{
	List<Student> l;
	Student stud;
	int flag = 1;
	while (flag)
	{
		do
		{
			char ch[40];
			print_functionMain();
			std::cin >> ch;
			flag = CharToInt(ch);
		} while (flag > 8 || flag < 0);

		switch (flag)
		{
		case 1:
		{
			DrawAllStud(l);
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "Введите номер зачетки студента: ";
			char numb[20] = {};
			std::cin >> numb;
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
			system("cls");
			std::cout << "Введите номер зачетки студента: ";
			char numb[20] = {};
			std::cin >> numb;
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
			std::cin >> numb;
			char fiel[] = "f.txt";
			for (int i = 0; i < l.Get_Size()-1; i++)
			{
			    if(!strcmp(numb, l[i].Get_Num())) continue;
				l[i].WriteInfoIntoFile(fiel);
			}
			remove(FielName);
			rename(fiel, FielName);
			break;
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
			break;
		}
		case 7:
		{
			IndividualTask(l);
			break;
		}
		case 8:
		{
			l.clear();
			stud.ReadAllStud(l, FielName);
			std::cout << l.Get_Size() << std::endl;
			break;
		}
		case 0:
			break;
		default:
		{
			std::cout << "error number" << std::endl;
			break;
		}

		}

		if (!flag) break;
	}



}