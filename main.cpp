// Retry1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>

#include "roster.h"

using namespace std;

const string studentData[] =
{ 
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,David,Aamodt,daamodt@wgu.edu,23,15,21,46,SOFTWARE"
};

int i = 0;
int dataSize = 5;


int main()
{
    cout << "Course: Scripting and Programming - Applicaions\nLanguage: C++\nStudent ID:003303454\nName: David Aamodt" << endl << endl;

    Roster classRoster;

    while (i < dataSize) {

        classRoster.parse(studentData[i]);
        i++;
    }

    classRoster.printAll();

    cout << endl;

    classRoster.printInvalidEmails();

    cout << endl;

    i = 0;

    while (i < dataSize) {
        classRoster.printAverageDaysInCourse(classRoster.getStudtentID(i));
        i++;
    }

    cout << endl;

    cout << "Software Students:" << endl;

    classRoster.printByDegreeProgram(SOFTWARE);

    cout << endl;

    classRoster.remove("A3");

    cout << endl;

    classRoster.printAll();

    cout << endl;

    classRoster.remove("A3");

    cout << endl;

    //Destructor is called when main is finished 
}
