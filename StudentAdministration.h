#include <string>
#include "Student.h"
using namespace std;

#ifndef STUDENTADMINISTRATION_H_INCLUDED
#define STUDENTADMINISTRATION_H_INCLUDED

class StudentAdministration
{ 
  string FacultyName;
  public:
    StudentAdministration (string facultyName);
    void write_student();    	       //write the record in binary file
    void display_all();	     	       //read all records from binary file
    void display_specifiedStudent(int);//accept ID and read record from binary file
    void modify_student(int);	       //accept ID and update record of binary file
    void delete_student(int);	       //accept ID and delete selected records from binary file
    void display_faculty_result();	   //display all records in tabular format from binary file
    void display_faculty_info_menu();	   //display result menu 
    void display_entry_menu();	       //display entry menu on screen
    student findStudentByNameAndPassword(const char* facultyNumber,
                                         const char* password); //Find student by id(facultyNumber) and password

}; 

#endif // STUDENTADMINISTRATION_H_INCLUDED