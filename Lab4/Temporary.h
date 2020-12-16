#pragma once
#include<string>
#include "../Lab2/date.h"

using namespace std;

class Temporary
{
private:
	string first_name, family_name;
	static int count;
protected:
	Date begin, end;
	virtual string emp_name();
	virtual string get_dates();
public:
	Temporary(string _first_name, string _family_name, Date _begin = Date(), Date _end = Date());
	virtual string PrintInfo();
	static int GetCount();
};
