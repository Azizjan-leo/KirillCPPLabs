#include "Secretary.h"

int Secretary::count = 0;

string Secretary::emp_name()
{
	return string("Secretary");
}

Secretary::Secretary(string _first_name, string _family_name, int _department, char _middle_name_init_letter, Date _hiringDate) : Employee(_first_name, _family_name, _middle_name_init_letter, _department, _hiringDate)
{
	count++;
}

string Secretary::PrintInfo()
{
	return string(Employee::PrintInfo());
}

int Secretary::GetCount()
{
	return count;
}


