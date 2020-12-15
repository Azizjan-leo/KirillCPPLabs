#pragma once
#include<string>
#include "../Lab2/date.h"

using namespace std;

class Temporary
{
private:
	string first_name, family_name;
	Date begin, end;
public:
	Temporary(string _first_name, string _family_name, Date _begin = Date(), Date _end = Date());
};

