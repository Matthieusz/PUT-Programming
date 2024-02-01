#include <iostream>
#include "staff.h"
#include "person.h"
using namespace std;

Staff::Staff(string name, string surname, float weight, float height, int age, Gender gender, string companyName, string position, float salary, float yearsOfExperience)
	: Person(name, surname, weight, height, age, gender), companyName(companyName), position(position), salary(salary), yearsOfExperience(yearsOfExperience) {}
int Staff::calculateYearsToRetirement() {
	int retirementAge = (gender == M ? 65 : 60);
	return retirementAge - getAge();
}