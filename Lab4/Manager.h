#pragma once
#include "Employee.h"
#include <set>

class Manager : protected Employee
{
private:
	short int level;
	std::set<Employee*> group; 
protected:
	string virtual emp_name() override;
public:
	Manager(string _first_name, int _department, short int _level, char _middle_name_init_letter = 32, set<Employee*> _group = set<Employee*>(), Date _hiringDate = Date());
	Manager(string _first_name, string _family_name, char _middle_name_init_letter, int _department, short int _level, set<Employee*> _group = set<Employee*>(), Date _hiringDate = Date());
	string virtual PrintInfo() override;
};

