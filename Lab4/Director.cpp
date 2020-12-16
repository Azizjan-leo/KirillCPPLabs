#include "Director.h"

int Director::count = 0;

Director::Director(string _first_name, string _family_name, char _middle_name_init_letter, short int _level, set<Employee*> _group, Date _hiringDate) : Manager(_first_name, _family_name, _middle_name_init_letter, 0, _level, _group, _hiringDate)
{
	count++;
}

string Director::PrintInfo()
{
	return Manager::PrintInfo();
}


int Director::GetCount()
{
	return count;
}

string Director::emp_name()
{
	return string("Director");
}
