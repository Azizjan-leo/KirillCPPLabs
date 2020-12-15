#include "Director.h"

Director::Director() : Manager("DF", "df", 32, 0, 5, set<Employee*>(), Date())
{

}

Director::Director(string _first_name, string _family_name, char _middle_name_init_letter, short int _level, set<Employee*> _group, Date _hiringDate) : Manager(_first_name, _family_name, _middle_name_init_letter, 0, _level, _group, _hiringDate)
{
}

string Director::PrintInfo()
{
	return Manager::PrintInfo();
}

string Director::emp_name()
{
	return string("Director");
}
