#include "Consultant.h"

Consultant::Consultant(std::string first_name, std::string family_name, Date begin, Date end, int _someData) : someData(_someData), Temporary(first_name, family_name, begin, end)
{
}