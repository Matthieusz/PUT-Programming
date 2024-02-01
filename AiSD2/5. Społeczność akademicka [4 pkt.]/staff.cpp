#include <iostream>
#include "staff.h"
#include "person.h"
using namespace std;

Staff::Staff(string name, string surname, float weight, float height, int age, Gender gender, string companyName, string job, float salary, float seniority) : 
	Person(name, surname, weight, height, age, gender), companyName_(companyName), job_(job), salary_(salary), seniority_(seniority) {}

int Staff::timeLeftToRetire() {
	int retireAge = (gender_ == Gender::K) ? 60 : 65;
	return retireAge - getAge();
}