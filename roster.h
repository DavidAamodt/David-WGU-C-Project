#pragma once
#include "student.h"
#include <string>

using namespace std;


class Roster {

public:
	Roster();
	~Roster();

	void parse(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void printInvalidEmails();
	void setRosterSize(int rosterSize);
	int getRosterSize();
	void resetPrintNumber();
	string getStudtentID(int arrayNumber);

private:
	Student* classRosterArray[5] = {};
	int rosterSize;
	int printNumber;
	int student;
	int avgDays;
	int totalDays;
	string id;
	const string emailTest = "A";
	const int rosterMax = 5;
};