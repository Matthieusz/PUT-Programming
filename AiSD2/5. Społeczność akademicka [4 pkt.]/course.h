#pragma once
#include <iostream>
#include <vector>
#include "student.h"
using namespace std;

class Course {
private:
    string courseName_;
    vector<vector<Student>> studentList;
    int totalStudents_;
public:
    Course(string courseName);
    void addStudent(const Student& student, int);
    void removeStudent(const Student& student, int);
    void sortStudents(int yearOfStudy);
    void bestStudents(int yearOfStudy);
};