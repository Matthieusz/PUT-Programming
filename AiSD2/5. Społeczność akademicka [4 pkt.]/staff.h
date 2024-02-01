#pragma once
#include <iostream>
#include "person.h"

class Staff : public Person{
private:
	string companyName_;
	string job_;
	float salary_;
	float seniority_;
public:
	Staff(string name, string surname, float weight, float height, int age, Gender gender, string companyName, string job, float salary, float seniority);
	int timeLeftToRetire();
};