#pragma once
#include<string>
#include "../Lab2/date.h"
#include <fstream>

using namespace std;

class Employee
{
private:
	static int count;
protected:
	string first_name, family_name;
	char middle_name_init_letter;
	short int department;
	Date hiring_date;
	virtual string emp_name();
public:
	Employee(string _first_name, int _department, char _middle_name_init_letter = 32, Date _hiring_date = Date());
	Employee(string _first_name, string _family_name, char _middle_name_init_letter, int _department, Date _hiringDate = Date());
	Employee(ifstream& ifs);
	virtual string PrintInfo();
	static int GetCount();
};