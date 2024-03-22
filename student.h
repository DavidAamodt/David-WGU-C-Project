#pragma once
#include "degree.h"
#include <string>

using namespace std;

class Student {

public:

	Student(string inID, string inFirst, string inLast, string inEmail, int inAge, int inDays1, int inDays2, int inDays3, DegreeProgram inDegree);
	Student();
	~Student();

	//D2b mutator function for each instance variable
	void setID(string inID);
	void setFirst(string inFirst);
	void setLast(string inLast);
	void setEmail(string inEmail);
	void setAge(int inAge);
	void setDays(int inDays1, int inDays2, int inDays3);
	void setDegree(DegreeProgram inDegree);

	//D2a accessor function for each instance variable
	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProgram getDegree();

	void print();



private:
	//D1 variables made within student class
	//D2c instance variables are private, must use public functions to access
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeprogram;

};



