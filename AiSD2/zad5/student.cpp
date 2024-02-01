#include <iostream>
#include "student.h"
#include "person.h"
using namespace std;

Student::Student(string name, string surname, float weight, float height, int age, Gender gender, string indexNumber, int yearOfStudy, const double grades[10])
	: Person(name, surname, weight, height, age, gender), indexNumber(indexNumber), yearOfStudy(yearOfStudy) {
	for (int i = 0; i < 10; i++) {
		this->grades[i] = grades[i];
	}
}
double Student::calculateAverageGrade() {
	double sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += grades[i];
	}
	return sum / 10;
}

string Student::getIndexNumber() {
	return indexNumber;
}