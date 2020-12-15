#pragma once
#include "Temporary.h"
#include "Secretary.h"

class Tsec : public Temporary, public Secretary
{
public:
	Tsec(string _first_name, char _middle_name_init_letter, int _department, string _family_name, Date _hiring_date, Date _begin = Date(), Date _end = Date());
};

