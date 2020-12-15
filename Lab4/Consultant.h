#pragma once
#include "Temporary.h"

class Consultant : public Temporary
{
private:
	int someData;
public:
	Consultant(std::string first_name, std::string family_name, Date begin = Date(), Date end = Date(), int _someData = 0);
};

