#include "Consultant.h"

int Consultant::count = 0;

Consultant::Consultant(std::string first_name, std::string family_name, Date begin, Date end) : Temporary(first_name, family_name, begin, end)
{
    count++;
}

int Consultant::GetCount()
{
    return count;
}

string Consultant::emp_name()
{
    return string("Consultant");
}
