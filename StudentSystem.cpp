#include<fstream>
#include<string.h> 
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstdio> 
#include "StudentSystem.h"

StudentSystem::StudentSystem(student st)
{
    loggedStudent=st;
}

StudentInfomatonSystem :: StudentInfomatonSystem(student st):StudentSystem(st)
{
}

void StudentInfomatonSystem::showInitialScreen()
{
    cout <<"\n====STUDENT INFORMATION===\n";
    loggedStudent.showdata();
    
    if(loggedStudent.getFinalGrade()<2.5)
    {
        cout <<"\nYou are not passed!\n";
    }
    else 
    {
        cout <<"\nCongratulations! You are passed\n";
    }
}

StudentEvaluationSystem :: StudentEvaluationSystem(student st):StudentSystem(st)
{
}

void StudentEvaluationSystem :: setCourseName(string course)
{
    courseName = course;
}

 void StudentEvaluationSystem :: setCommentContent(string comment)
{
    commentAboutTheCourse = comment;
}

void StudentEvaluationSystem :: writeCommentAboutCourse ()
{
  ofstream myfile;
  myfile.open ("coursecomments.txt",fstream::trunc);
  myfile << "-----------------------------------------\n"
         << "Author < "
         << loggedStudent.getFacultyNumber()
         << ">\n"
         << "course <"
         << courseName
         << ">\n"
         <<"Comment content:"
         << commentAboutTheCourse
         << endl
         <<"-----------------------------------------";
  myfile.close();
}

void StudentEvaluationSystem :: showInitialScreen ()
{
    string courseName,commentContent;
    cout <<"\nInsert course name: ";
    cin  >> courseName;
    cout <<"\nInsert content of the comment :";
    cin >> commentContent;
    
    setCourseName(courseName);
    setCommentContent(commentContent);
    writeCommentAboutCourse();
    
    cout <<"\nComment created\n";
}



