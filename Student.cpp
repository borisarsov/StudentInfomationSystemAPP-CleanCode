#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstdio>
#include "Student.h"

using namespace std;

void student::calculateFinalGrade()
{
	finalGrade=(
	           cleanCodeGrade + algorithmsGrade
	           +mathematicsGrade + englishGrade
	           +programmingGrade
	           )/5.0; 
}

void student::getdata()
{
	cout<<"\nEnter The ID of student (faculty number )";
	cin>>facultyNumber;
	cout<<"\nEnter student Sys password :\n";
	cin >> studentPassword;
	cout<<"\nEnter The Name of student : "             ;
	cin>>studentName;
	cout<<"\nEnter The mark  in CleanCode (2-6) : "    ;
	cin>>cleanCodeGrade;
	cout<<"\nEnter The mark in Algorithms (2-6) : "    ;
	cin>>algorithmsGrade;
	cout<<"\nEnter The mark in Maths (2-6) : "         ;
	cin>>mathematicsGrade;
	cout<<"\nEnter The mark in English (2-6) : "       ;
	cin>>englishGrade;
	cout<<"\nEnter The mark in Programming (2-6) : "   ;
	cin>>programmingGrade;
	calculateFinalGrade();
}

void student::showdata()
{
	cout<<"\nID (faculty) number of student : " <<facultyNumber;
	cout<<"\nSys pasword          : "           <<studentPassword;
	cout<<"\nName of student      : "           <<studentName;
	cout<<"\nMarks in Clean Code  : "           <<cleanCodeGrade;
	cout<<"\nMarks in Algorithms  : "           <<algorithmsGrade;
	cout<<"\nMarks in Maths       : "           <<mathematicsGrade;
	cout<<"\nMarks in English     : "           <<englishGrade;
	cout<<"\nMarks in Programming : "           <<programmingGrade;
	cout<<"\nPercentage of student (final grade) is: "<<finalGrade; 
}

/*  The records will be presented in following format 
    ================================================== 
    R.No       Name       CC   Al   M   E   P    %age   
    ==================================================
    ..................................................
*/
void student::show_tabular()
{
	cout <<facultyNumber   <<setw(6) << "  "
	     <<studentName     <<setw(10)
	     <<cleanCodeGrade  <<setw(4)
	     <<algorithmsGrade <<setw(4)
	     <<mathematicsGrade<<setw(4)
	     <<englishGrade    <<setw(4)
	     <<programmingGrade<<setw(4) << "  "
	     <<finalGrade      <<endl;
}

int  student::getFacultyNumber()
{
	return facultyNumber;
}
char*  student::getPassword()
{
	return studentPassword;
}
float  student::getFinalGrade()
{
	return finalGrade;
}
