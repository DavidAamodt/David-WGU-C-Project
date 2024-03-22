#include <iostream>

#include <string>

#include "roster.h"



using namespace std;




Roster::Roster()
{
	setRosterSize(0);
}

Roster::~Roster()
{
	for (int i = 0; i < rosterSize; i++)
		delete classRosterArray[i];
	cout << "Destructor Called" << endl;
}

void Roster::parse(string row)
{
	size_t rhs = row.find(",");
	string parseID = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string parseFirst = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string parseLast = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string parseEmail = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int parseAge = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int parseDays1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int parseDays2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int parseDays3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string parseStrDegree = row.substr(lhs, rhs - lhs);
	DegreeProgram parseDegree = SECURITY;
	if (parseStrDegree == "SOFTWARE") {
		parseDegree = DegreeProgram::SOFTWARE;
	}
	else if (parseStrDegree == "NETWORK") {
		parseDegree = DegreeProgram::NETWORK;
	}

	add(parseID, parseFirst, parseLast, parseEmail, parseAge, parseDays1, parseDays2, parseDays3, parseDegree);

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	classRosterArray[getRosterSize()] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	setRosterSize(getRosterSize() + 1);
}

void Roster::remove(string studentID)
{
	cout << "Student '" << studentID << "' ";
	bool wasFound = false;
	int i = 0;

	while (i < getRosterSize()) {
		if (studentID == classRosterArray[i]->getID()) {
			wasFound = true;
			delete classRosterArray[i];
			setRosterSize(getRosterSize() - 1);
			this->classRosterArray[i] = this->classRosterArray[getRosterSize()];
			cout << "has been removed" << endl;
		}
		i++;
	}
	if (wasFound == false)
		cout << "was not found" << endl;
}

void Roster::printAll()
{
	resetPrintNumber();
	while (printNumber < getRosterSize()) {
		classRosterArray[printNumber]->print();
		printNumber = printNumber + 1;
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	student = 0;

	while (classRosterArray[student]->getID() != studentID) {
		student++;
	}

	int totalDays = classRosterArray[student]->getDays()[0] + classRosterArray[student]->getDays()[1] + classRosterArray[student]->getDays()[2];
	int avgDays = totalDays / 3;
	cout << classRosterArray[student]->getFirst() << " " << classRosterArray[student]->getLast() << "'s Average Days In Course is " << avgDays << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	int i = 0;
	
	while (i < getRosterSize()) {
		if (classRosterArray[i]->getDegree() == degreeprogram) {
			classRosterArray[i]->print();
		}
		i++;
	}
}

void Roster::printInvalidEmails()
{
	const size_t notFound = emailTest.find("@");
	int i = 0;

	cout << "Invalid Email List: " << endl;

	while (i < getRosterSize()) {
		string currentEmail = classRosterArray[i]->getEmail();
		
		if (currentEmail.find("@") == notFound) {
			cout << currentEmail << endl;
		}
		else if (currentEmail.find(".") == notFound) {
			cout << currentEmail << endl;
		}
		else if (currentEmail.find(" ") != notFound) {
			cout << currentEmail << endl;
		}
		i++;
	}
}

void Roster::setRosterSize(int rosterSize)
{
	this->rosterSize = rosterSize;
}

int Roster::getRosterSize()
{
	return rosterSize;
}

void Roster::resetPrintNumber()
{
	this->printNumber = 0;
}

string Roster::getStudtentID(int arrayNumber)
{
	return classRosterArray[arrayNumber]->getID();
}

