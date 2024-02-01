#include <iostream>
#include "student.h"
#include "person.h"
using namespace std;

Student::Student(string name, string surname, float weight, float height, int age, Gender gender, string indexNumber, int yearOfStudy, const double gradeTab[]) :
	Person(name, surname, weight, height, age, gender), indexNumber_(indexNumber), yearOfStudy_(yearOfStudy) {
	for (int i = 0; i < 5; ++i) {
		this->gradeTab[i] = gradeTab[i];
	}
}

double Student::countAverageGrade() {
	double sum = 0;
	int gradeCount = 0;
	for (int i = 0; i < 10; ++i) {
		if (gradeTab[i] > 0) {
			sum += gradeTab[i];
			gradeCount++;
		}
	}
	return (gradeCount > 0) ? (sum / gradeCount) : 0;
}

void Student::displayIndex() {
	cout << indexNumber_ << " ";
}