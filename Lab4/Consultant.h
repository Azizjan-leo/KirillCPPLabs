#pragma once
#include "Temporary.h"

class Consultant : public Temporary
{
private:
	static int count;
protected:
	virtual string emp_name() final;
public:
	Consultant(std::string first_name, std::string family_name, Date begin = Date(), Date end = Date());
	using Temporary::PrintInfo;
	static int GetCount();
};
