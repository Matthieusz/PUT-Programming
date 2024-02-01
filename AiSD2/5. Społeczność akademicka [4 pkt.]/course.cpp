#include <iostream>
#include "course.h"
#include "student.h"
using namespace std;

Course::Course(string courseName) : courseName_(courseName), totalStudents_(0) {}

void Course::addStudent(const Student& student, int year) {
	studentList[year].push_back(student);
	totalStudents_++;
}

void Course::removeStudent(const Student& student, int year) {
	studentList[year].pop_back();
	totalStudents_--;
}

void Course::sortStudents(int yearOfStudy) {
	float max = studentList[yearOfStudy][0].countAverageGrade();
	int maxIndex = 0;
	float min = 0;
	for (int i = 0; i < studentList[yearOfStudy].size(); i++) {
		if (studentList[yearOfStudy][i].countAverageGrade() > max) {
			float temp = max;
			max = studentList[yearOfStudy][i].countAverageGrade();
			maxIndex = i;
		}
	}
	//TODO
}

void Course::bestStudents(int yearOfStudy) {
	sortStudents(yearOfStudy);
	for (int i = 0; i < 3; i++) {
		studentList[yearOfStudy][i].displayIndex();
		studentList[yearOfStudy][i].displayInfo();
	}
}