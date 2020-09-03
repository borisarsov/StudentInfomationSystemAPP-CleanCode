#ifndef STUDENTSYSTEM_H_INCLUDED
#define STUDENTSYSTEM_H_INCLUDED

#include <string>
#include "Student.h"
using namespace std;

class StudentSystem
{
protected:
	student loggedStudent;	 
public: 
    StudentSystem (student st);
    virtual void showInitialScreen() { };
}; 

class StudentInfomatonSystem:public StudentSystem
{ 
    public:
    StudentInfomatonSystem(student st);
    void showInitialScreen();
};

class StudentEvaluationSystem : public StudentSystem
{   
    string commentAboutTheCourse;
    string courseName;
    
    public:
    StudentEvaluationSystem(student st);
    void setCommentContent(string comment);
    void setCourseName(string course);
    void writeCommentAboutCourse();
    void showInitialScreen();
};
#endif // STUDENTSYSTEM_H_INCLUDED