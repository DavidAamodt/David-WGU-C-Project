#include <iostream>

#include <string>

#include <iomanip>

#include "student.h"

using namespace std;

Student::Student(string inID, string inFirst, string inLast, string inEmail, int inAge, int inDays1, int inDays2, int inDays3, DegreeProgram inDegree)
{
	setID(inID);
	setFirst(inFirst);
	setLast(inLast);
	setEmail(inEmail);
	setAge(inAge);
	setDays(inDays1, inDays2, inDays3);
	setDegree(inDegree);
}

Student::Student()
{
	setID("none");
	setFirst("none");
	setLast("none");
	setEmail("none");
	setAge(0);
	setDays(0, 0, 0);
	setDegree(SOFTWARE);
}

Student::~Student()
{
}

void Student::setID(string inID)
{
	this->studentID = inID;
}

void Student::setFirst(string inFirst)
{
	this->firstName = inFirst;
}

void Student::setLast(string inLast)
{
	this->lastName = inLast;
}

void Student::setEmail(string inEmail)
{
	this->emailAddress = inEmail;
}

void Student::setAge(int inAge)
{
	this->age = inAge;
}

void Student::setDays(int inDays1, int inDays2, int inDays3)
{
	this->daysInCourse[0] = inDays1;
	this->daysInCourse[1] = inDays2;
	this->daysInCourse[2] = inDays3;
}

void Student::setDegree(DegreeProgram inDegree)
{
	this->degreeprogram = inDegree;
}

string Student::getID()
{
	return this -> studentID;
}

string Student::getFirst()
{
	return this -> firstName;
}

string Student::getLast()
{
	return this -> lastName;
}

string Student::getEmail()
{
	return this-> emailAddress;
}

int Student::getAge()
{
	return this-> age;
}

int* Student::getDays()
{
	return this-> daysInCourse;
}

DegreeProgram Student::getDegree()
{
	return this-> degreeprogram;
}

void Student::print()
{
	string strDegree = "SECURITY";
	if (getDegree() == SOFTWARE) {
		strDegree = "SOFTWARE";
	}
	else if (getDegree() == NETWORK) {
		strDegree = "NETWORK";
	}
	cout << getID() << "\t";
	cout << "First Name: " << getFirst() << "\t";
	cout << "Last Name: " << getLast() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "daysInCourse: {" << getDays()[0] << ", ";
	cout << getDays()[1] << ", ";
	cout << getDays()[2] << "} ";
	cout << "Degree Program: " << strDegree;
	cout << endl;
}




