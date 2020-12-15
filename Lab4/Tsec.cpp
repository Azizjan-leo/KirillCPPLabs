#include "Tsec.h"

Tsec::Tsec(string _first_name, char _middle_name_init_letter, int _department, string _family_name, Date _hiring_date, Date _begin, Date _end) : 
	Temporary(_first_name, _family_name, _begin, _end), Secretary(_first_name, _family_name, _middle_name_init_letter, _department, _hiring_date)
{
}
