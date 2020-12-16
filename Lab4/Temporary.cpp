#include "Temporary.h"

int Temporary::count = 0;

string Temporary::emp_name()
{
    return string("Temporary");
}

string Temporary::get_dates()
{
    return string("Begin: " + begin.getDate() + "\nEnd: " + end.getDate());
}

Temporary::Temporary(string _first_name, string _family_name, Date _begin, Date _end) : first_name(_first_name), family_name(_family_name), begin(_begin), end(_end)
{
    count++;
}

string Temporary::PrintInfo()
{
    string empName = emp_name();
    string dates = get_dates();
    return string(empName + "!\nFirst name: " + first_name + "\nLast name: " + family_name + "\n" + dates);
}

int Temporary::GetCount()
{
    return count;
}
