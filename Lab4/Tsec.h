#pragma once
#include "Temporary.h"
#include "Secretary.h"

class Tsec : protected Temporary, public Secretary
{
private:
	static int count;
protected:
	virtual string emp_name() final;
	virtual string get_dates() final;
public:
	Tsec(string _first_name, string _family_name, int _department, char _middle_name_init_letter = 32, Date _hiring_date = Date(), Date _begin = Date(), Date _end = Date());
	virtual string PrintInfo() final;
	static int GetCount();
};