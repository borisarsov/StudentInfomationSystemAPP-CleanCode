#include<fstream>
#include<string.h> 
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstdio> 
#include "Student.h"
#include "StudentAdministration.h"

using namespace std;

StudentAdministration::StudentAdministration(string facultyName)
{
    FacultyName = facultyName;
}

void StudentAdministration::write_student()
{
	student st;
	ofstream outFile;
	outFile.open("students.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(student));
	outFile.close();
    cout<<"\nStudent record has been c reated ";
	cin.ignore();
	getch();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************
void StudentAdministration::display_all()
{
	student st;
	ifstream inFile;
	inFile.open("students.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open ! Press any Key...";

		getch();
		return;
	}
	cout<<"\nDISPLAY ALL RECORDS FOR FACULTY <"<<FacultyName<<"> \n\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.showdata();
		cout<<"\n====================================\n";
	}
	inFile.close();

	getch();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************
void StudentAdministration::display_specifiedStudent(int n)
{
	student st;
	ifstream inFile;
	inFile.open("students.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened ! Press any Key...";

		getch();
		return;
	}
	int flag=0;
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.getFacultyNumber()==n)
		{
			 st.showdata();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\nrecord not exist";

	getch();
}

void StudentAdministration::modify_student(int n)
{
	int found=0;
	student st;
	fstream File;
	File.open("students.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}

	while(File.read((char *) &st, sizeof(student)) && found==0)
	{
		if(st.getFacultyNumber()==n)
		{
			st.showdata();
			cout<<"\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    const int pos=(-1)*(int)sizeof(st);
		    File.seekp(pos,ios::cur);
		    File.write((char *) &st, sizeof(student));
		    cout<<"\nRecord Updated";
		    found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n  Record Not Found ";
	getch();
}

void StudentAdministration::delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("students.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.getFacultyNumber()!=n)
		{
			outFile.write((char *) &st, sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("students.dat");
	rename("Temp.dat","students.dat");
	cout<<"\nRecord Deleted ..";

	getch();
}

/*  The records will be presented in following format 
    ================================================== 
    R.No       Name       CC   Al   M   E   P    %age   
    ==================================================
    ..................................................
*/
void StudentAdministration::display_faculty_result()
{
	student st;
	ifstream inFile;
	inFile.open("students.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	cout<<"\n ALL STUDENTS RESULT: FACULTY <"<<FacultyName<<"> \n\n";
	cout<<"==================================================\n";
	cout<<"R.No       Name       CC   Al   M   E   P    %age  "<<endl;
	cout<<"==================================================\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.show_tabular();
	}

	getch();
	inFile.close();
}

void StudentAdministration::display_faculty_info_menu()
{
	char ch;
	int rno;
	cout<<"\n FACULTY INFORMATION"  ;
	cout<<"\n FACULTY NAME : <"     <<FacultyName <<">";
	cout<<"\n1. All students result";
	cout<<"\n2. Student report"     ;
	cout<<"\n3. Back to Main Menu"  ;
	cout<<"\nEnter Choice (1/2/3)? ";
	cin>>ch; 
	switch(ch)
	{
	case '1' :	display_faculty_result(); break;
	case '2' :	cout<<"\nEnter Faculty Number Of Student : "; cin>>rno;
				display_specifiedStudent(rno); break;
	case '3' :	break;
	default:	cout<<"\a Wrong input";
	}
}

void StudentAdministration::display_entry_menu()
{
	cout<<"\nSTUDENT MANANGER MANU"          ;
	cout<<"\n1.CREATE STUDENT RECORD"        ;
	cout<<"\n2.DISPLAY ALL STUDENTS RECORDS" ;
	cout<<"\n3.SEARCH STUDENT RECORD "       ;
	cout<<"\n4.MODIFY STUDENT RECORD"        ;
	cout<<"\n5.DELETE STUDENT RECORD"        ;
	cout<<"\n6.BACK TO MAIN MENU"            ;
	cout<<"\nPlease enter your choice (1-6) ";

	char ch;
	int  facNum;
	
	cin>>ch; 
	
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\nPlease ernter the faculty number "; cin>>facNum;
				display_specifiedStudent(facNum); break;
	case '4':	cout<<"\nPlease enter the faculty number "; cin>>facNum;
				modify_student(facNum);break;
	case '5':	cout<<"\nPlease enter the faculty number "; cin>>facNum;
				delete_student(facNum);break;
	case '6':	break;
	default:	cout<<"\a Wrong input"; display_entry_menu();
	}
}

student StudentAdministration::findStudentByNameAndPassword(const char * facultyNumber,
                                                            const char * password)
{
    student st ;
	ifstream inFile;
	inFile.open("students.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened ! Press any Key...";
        exit(3);
	}
	int flag=0;
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.getFacultyNumber()==atoi(facultyNumber) && strcmp(st.getPassword(),password)==0 )
		{
			 flag=1;
			 break;
		}
	}
	inFile.close();
	if(flag==0)
	{
		cout<<"\nRecord not exist";
		exit(2);
	}
   
   return st;
	 
}