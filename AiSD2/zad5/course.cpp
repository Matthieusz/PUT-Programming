#include <iostream>
#include "course.h"
#include "student.h"
using namespace std;

Course::Course(string courseName) : courseName(courseName), totalStudents(0) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			studentList[i][j] = nullptr;
		}
	}
}

void Course::addStudent(Student* student, int year) {
        for (int i = 0; i < 10; i++) {
            if (studentList[year - 1][i] == nullptr) {
                studentList[year - 1][i] = student;
                totalStudents++;
                break;
            }
        }
    }

void Course::removeStudent(Student* student, int year) {
	for (int i = 0; i < 10; i++) {
		if (studentList[year - 1][i] == student) {
			studentList[year - 1][i] = nullptr;
			totalStudents--;
			break;
		}
	}
}

void Course::sortStudents(int year) { //do poprawy
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (studentList[year - 1][j] != nullptr && studentList[year - 1][j + 1] != nullptr) {
                if (studentList[year - 1][j]->calculateAverageGrade() < studentList[year - 1][j + 1]->calculateAverageGrade()) {
                    Student* temp = studentList[year - 1][j];
                    studentList[year - 1][j] = studentList[year - 1][j + 1];
                    studentList[year - 1][j + 1] = temp;
                }
            }
        }
    }
}

void Course::displayBestStudents(int year) { //do poprawy
    sortStudents(year);
    for (int i = 0; i < 3; i++) {
        if (studentList[year - 1][i] != nullptr) {
            cout << studentList[year - 1][i]->getIndexNumber() << " "
                 << studentList[year - 1][i]->getName() << " "
                 << studentList[year - 1][i]->getSurname() << " ";
        }
    }
}