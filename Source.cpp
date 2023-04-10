#include <iostream>
#include "Libruaries.h"
#include <fstream>


void Draw(List<Student>& l)
{

}


int main()
{
	Student stud;
	Burn data;
	Subject sub[10];
	sub[0].Set_All((char*)"fiz", '5');
	sub[1].Set_All((char*)"him", '2');
	Session ses[9];
	ses[0].Set_Session(sub);
	ses[1].Set_Session(sub);
	ses[2].Set_Session(sub);
	
	data.Set_Data(11, 12, 2004);
	char department[20] = "Departamentaaaaaa";
	char faculty[40] ="facultqqqqy";
	char group[10] = "groupzzz";
	char number[20] = "numberasdqqqq";
	char first_name[30] = "first_name";
	char second_name[30] = "second_name";
	char thired_name[30] = "thired_name";
	unsigned int enter_year=123123;
	char flor[10] = "man";
	char file[] = "File.txt";
	char dep[] = "DEPARTMENT";
	stud.Set_Dep(department);
	stud.Set_Sn(second_name);
	stud.Set_EnterYear(enter_year);
	stud.Set_Fac(faculty);
	stud.Set_Flor(flor);
    stud.Set_FN(first_name);
	stud.Set_Gr(group);
	stud.Set_Num(number);
	stud.Set_TN(thired_name);
	stud.Set_Ses(ses);
	stud.Set_Data(data);


	stud.WriteInfoIntoFile(file);
	
	Student st;
	st.ReadInfoFormFile(number,file);
	std::cout << st.Get_FN() << " " << st.Get_Dep() << " " << st.Get_EnterYear() << " " << st.Get_Fac() << std::endl;
	st.Set_Dep(dep);
	std::cout << st.Get_FN() << " " << st.Get_Dep() << " " << st.Get_EnterYear() << " " << st.Get_Fac() << std::endl;
	st.ChangeInfoName(file);
	st.ReadInfoFormFile(number, file);
	std::cout << st.Get_FN() << " " << st.Get_Dep() << " " << st.Get_EnterYear() << " " << st.Get_Fac() << std::endl;
	
	
	return 0;
}