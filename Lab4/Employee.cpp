#include "Employee.h"

int Employee::count = 0;

string Employee::emp_name()
{
    return string("Employee");
}

Employee::Employee(string _first_name, int _department, char _middle_name_init_letter, Date _hiring_date)
    : first_name(_first_name), department(_department), hiring_date(_hiring_date), middle_name_init_letter(_middle_name_init_letter)
{
    count++;
}
Employee::Employee(string _first_name, string _family_name, char _middle_name_init_letter, int _department, Date _hiringDate) : first_name(_first_name), family_name(_family_name), middle_name_init_letter(_middle_name_init_letter), department(_department), hiring_date(_hiringDate)
{
    count++;
}

Employee::Employee(ifstream& ifs)
{
    ifs >> first_name >> department;
    middle_name_init_letter = 32;
    count++;
}

string Employee::PrintInfo()
{
    return string(emp_name() + "!\nFirst name: " + first_name + "\nMiddle name: " + middle_name_init_letter + "\nLast name: " + family_name + "\n" + "Department: " + to_string(department) + "\nHiring date: " + hiring_date.getDate());
}

int Employee::GetCount()
{
    return count;
}


