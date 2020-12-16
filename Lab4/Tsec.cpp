#include "Tsec.h"

int Tsec::count = 0;

string Tsec::emp_name()
{
	return string("Temp. secretary");
}

string Tsec::get_dates()
{
	return string(Temporary::get_dates() + "\nHiring date: " + Secretary::Employee::hiring_date.getDate());
}

Tsec::Tsec(string _first_name, string _family_name, int _department, char _middle_name_init_letter, Date _hiring_date, Date _begin, Date _end) :
	Temporary(_first_name, _family_name, _begin, _end), Secretary(_first_name, _family_name, _middle_name_init_letter, _department, _hiring_date)
{
	count++;
}

string Tsec::PrintInfo()
{
	return Temporary::PrintInfo();
}

int Tsec::GetCount()
{
	return count;
}
