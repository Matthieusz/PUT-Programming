#pragma once
#include <iostream>
#include "person.h"
using namespace std;

class Student: public Person {
private:
	string indexNumber_;
	int yearOfStudy_;
	double gradeTab[10];
public:
	Student(string name, string surname, float weight, float height, int age, Gender gender, string indexNumber, int yearOfStudy, const double gradeTab[]);
	double countAverageGrade();
	void displayIndex();
};