#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstdio> 
#include "StudentAdministration.h"
#include "StudentSystem.h"

using namespace std;

int main()
{
    
    StudentAdministration FMIstudentAdministration("FMI"); 
    
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); // program outputs decimal number to two decimal places 
	
	cout << "\nLOGIN IN SYSTEM AS:";
	cout << "\n01.Administrator "  ;
	cout << "\n02.Student       "  ;
	cout<<  "\nPlease Select Your Option (1 or 2 ) ?\n";
	
	char ch;
	cin >> ch;
    string username ,password;
    cout <<"\nUsername   :";
    cin  >> username ;
    cout << "\nPassword  :";
    cin  >> password;
    
	if(ch=='1' && username=="admin" && password=="admin")
	{
	  cout <<"\nSuccessfully loged as adminisitrator";
      do
      { 
	    cout<<"\nMAIN MENU"            ;
	    cout<<"\n01. FACULTY INFO MENU";
	    cout<<"\n02. ENTRY/EDIT MENU " ;
	    cout<<"\n03. EXIT"             ;
        cout<<"\nPlease Select Your Option (1-3) ";
	    cin>>ch; 
		    
	    switch(ch)
	    {
    		  case '1': FMIstudentAdministration.display_faculty_info_menu();
    		  break;
    		  case '2': FMIstudentAdministration.display_entry_menu();
    		  break;
    		  case '3':
    		  break;
    		  default :cout<<"\nInvalid input";
	    }
      }while(ch!='3');
	}
	else
	{
	  student st = FMIstudentAdministration.findStudentByNameAndPassword(username.c_str(),password.c_str());
	  char ch;
	  do{
    	  cout << "\nSTUDENT MENU";
    	  cout << "\n01.View student info";
    	  cout << "\n02.Evaluate course  ";
    	  cout << "\n03.EXIT             ";
          cout <<"\nPlease Select Your Option (1 or 2 ) ";
    	  cin>>ch;
    	  switch(ch)
    	  {
    		  case '1':{
    		    StudentSystem * externalInfoSystem = new  StudentInfomatonSystem(st) ;
    	        externalInfoSystem ->showInitialScreen();
    		  }
    		    break;
    		  case '2':{
    		    StudentSystem * externalEvolSystem = new  StudentEvaluationSystem(st) ;
                externalEvolSystem ->showInitialScreen();
    		  }
    		    break;
    		  case '3':
    		    exit(0);
    		    break;
    		  default :cout<<"\nInvalid input";
    	  }
        }while(ch!='3');
	}
	
	return 0;
} 