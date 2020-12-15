#pragma once
#include<string>
#include "../Lab2/date.h"

using namespace std;

class Employee
{
private:
	string first_name, family_name;
	char middle_name_init_letter;
	Date hiring_date;
	short int department;
public:
	Employee(string _first_name, string _family_name, char _middle_name_init_letter, int _department, Date _hiringDate = Date());
};

