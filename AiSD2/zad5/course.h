#pragma once
#include <iostream>
#include "student.h"
using namespace std;

class Course {
private:
    string courseName;
    Student* studentList[5][10];
    int totalStudents;
public:
    Course(string courseName);
    void addStudent(Student* student, int year);
    void removeStudent(Student* student, int year);
    void sortStudents(int year);
    void displayBestStudents(int year);
};