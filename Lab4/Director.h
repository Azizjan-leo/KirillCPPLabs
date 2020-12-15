#pragma once
#include "Manager.h"

class Director : protected Manager
{
protected:
	string virtual emp_name() final;
public:
	Director();
	Director(string _first_name, string _family_name, char _middle_name_init_letter = 32, short int _level = 5, set<Employee*> _group = set<Employee*>(), Date _hiringDate = Date());
	string virtual PrintInfo() final;
};

