#include "Manager.h"

string Manager::emp_name()
{
	return string("Manager");
}

Manager::Manager(string _first_name, int _department, short int _level, char _middle_name_init_letter, set<Employee*> _group, Date _hiringDate)
	: level(_level), group(_group), Employee(_first_name, "", _middle_name_init_letter, _department, _hiringDate)
{
}

Manager::Manager(string _first_name, string _family_name, char _middle_name_init_letter, int _department, short int _level, set<Employee*> _group, Date _hiringDate) : level(_level), group(_group), Employee(_first_name, _family_name, _middle_name_init_letter, _department, _hiringDate)
{
}

string Manager::PrintInfo()
{
	return string(Employee::PrintInfo() + "\nLevel: " + to_string(level));
}
