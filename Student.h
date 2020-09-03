#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
class student
{
	int   facultyNumber;
	char  studentName[50];
	int   cleanCodeGrade, algorithmsGrade, mathematicsGrade, englishGrade, programmingGrade;
	float finalGrade; 
	char  studentPassword[50] ;
	void  calculateFinalGrade();	 
public:
	void getdata();	    //function to accept data from student
	void showdata();	//function to show data on screen
	void show_tabular();//In tabular Mode 
	int  getFacultyNumber();
	char* getPassword();
	float getFinalGrade();
}; 

#endif // STUDENT_H_INCLUDED