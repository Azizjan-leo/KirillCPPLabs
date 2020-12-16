#pragma once
#include "Employee.h"
#include <string>

class Secretary : public Employee
{
private:
	static int count;
protected:
	string emp_name() override;
public:
	Secretary(string _first_name, string _family_name, int _department, char _middle_name_init_letter = 32, Date _hiringDate = Date());
	string PrintInfo() override;
	static int GetCount();
};