#include "StringNumConverter.h"

ostream& operator << (ostream& os, const StringNumConverter& other) {
	os << other.inp_str << endl;
	return os;
}

bool StringNumConverter::areEqual(string firstNum, string secondNum)
{
	if ((firstNum[0] != '-' && secondNum[0] == '-') || (firstNum[0] == '-' && secondNum[0] != '-'))
		return false;

	string thisStr(firstNum), otherStr(secondNum);

	if (firstNum.find('.') == std::string::npos)
		thisStr += ".0";
	if (secondNum.find('.') == std::string::npos)
		otherStr += ".0";

	int digit = stod(thisStr);
	digit;
	string thisBase(to_string(digit));
	string thisFraction(thisStr.substr(thisStr.find('.') + 1));
	digit = stod(otherStr);
	digit;
	string otherBase(to_string(digit));
	string otherFraction(otherStr.substr(otherStr.find('.') + 1));

	while (thisBase.size() != otherBase.size()) {
		if (thisBase.size() < otherBase.size())
			thisBase.insert(0, "0");
		else
			otherBase.insert(0, "0");
	}

	for (size_t i = 0; i < thisBase.size(); i++)
	{
		int thisNum = thisBase[i] - '0';
		int otherNum = otherBase[i] - '0';
		if (thisNum != otherNum)
			return false;
	}

	while (thisFraction.size() != otherFraction.size()) {
		if (thisFraction.size() < otherFraction.size())
			thisFraction += "0";
		else
			otherFraction += "0";
	}

	for (size_t i = 0; i < thisFraction.size(); i++)
	{
		int thisNum = thisFraction[i] - '0';
		int otherNum = otherFraction[i] - '0';
		if (thisNum != otherNum)
			return false; 
	}
	return true;
}

bool StringNumConverter::isGreater(string firstNum, string secondNum)
{
	if (firstNum[0] != '-' && secondNum[0] == '-')
		return true;
	if (firstNum[0] == '-' && secondNum[0] != '-')
		return false;
	if (firstNum[0] == '-' && secondNum[0] == '-')
	{
		string thisStr(firstNum.substr(1, firstNum.size() - 1)), otherStr(secondNum.substr(1, secondNum.size() - 1));
		if (firstNum.find('.') == string::npos)
			thisStr += ".0";
		if (secondNum.find('.') == string::npos)
			otherStr += ".0";

		int digit = stod(thisStr);
		digit *= -1;
		string thisBase(to_string(digit));
		string thisFraction(thisStr.substr(thisStr.find('.') + 1));
		digit = stod(otherStr);
		digit *= -1;
		string otherBase(to_string(digit));
		string otherFraction(otherStr.substr(otherStr.find('.') + 1));

		while (thisBase.size() != otherBase.size()) {
			if (thisBase.size() < otherBase.size())
				thisBase.insert(0, "0");
			else
				otherBase.insert(0, "0");
		}

		for (size_t i = 0; i < thisBase.size(); i++)
		{
			int thisNum = thisBase[i] - '0';
			int otherNum = otherBase[i] - '0';
			if (thisNum < otherNum)
				return true; // 'cuz it's a negative number :)
			else if (otherNum < thisNum)
				return false;
		}

		while (thisFraction.size() != otherFraction.size()) {
			if (thisFraction.size() < otherFraction.size())
				thisFraction += "0";
			else
				otherFraction += "0";
		}

		for (size_t i = 0; i < thisFraction.size(); i++)
		{
			int thisNum = thisFraction[i] - '0';
			int otherNum = otherFraction[i] - '0';
			if (thisNum < otherNum)
				return true; // 'cuz it's a negative number :)
			else if (otherNum < thisNum)
				return false;
		}

	}

	string thisStr(firstNum), otherStr(secondNum);

	if (firstNum.find('.') == std::string::npos)
		thisStr += ".0";
	if (secondNum.find('.') == std::string::npos)
		otherStr += ".0";

	int digit = stod(thisStr);
	digit;
	string thisBase(to_string(digit));
	string thisFraction(thisStr.substr(thisStr.find('.') + 1));
	digit = stod(otherStr);
	digit;
	string otherBase(to_string(digit));
	string otherFraction(otherStr.substr(otherStr.find('.') + 1));

	while (thisBase.size() != otherBase.size()) {
		if (thisBase.size() < otherBase.size())
			thisBase.insert(0, "0");
		else
			otherBase.insert(0, "0");
	}

	for (size_t i = 0; i < thisBase.size(); i++)
	{
		int thisNum = thisBase[i] - '0';
		int otherNum = otherBase[i] - '0';
		if (thisNum < otherNum)
			return false; // 'cuz it's a negative number :)
		else if (otherNum < thisNum)
			return true;
	}

	while (thisFraction.size() != otherFraction.size()) {
		if (thisFraction.size() < otherFraction.size())
			thisFraction += "0";
		else
			otherFraction += "0";
	}

	for (size_t i = 0; i < thisFraction.size(); i++)
	{
		int thisNum = thisFraction[i] - '0';
		int otherNum = otherFraction[i] - '0';
		if (thisNum < otherNum)
			return false; // 'cuz it's a negative number :)
		else if (otherNum < thisNum)
			return true;
	}
}

StringNumConverter::StringNumConverter(const char* line) {
	if (line == nullptr)
		throw invalid_argument("Invalid argument");
	string s(line);
	if (line[0] == '-')
	{
		s = s.substr(s.find('-') + 1);
		if(s.size() == 0)
			throw invalid_argument("Invalid argument");		
	}

	bool isDot = false;
	for (char& c : s) {
		switch (c)
		{
		case '.' :
			if (isDot)
				throw invalid_argument("Invalid argument");
			isDot = true;
			break;
		case '-':
			throw invalid_argument("Invalid argument");
			break;
		default:
			if(!isdigit(c))
				throw invalid_argument("Invalid argument");
			break;
		}
	}
	inp_str = string(line);
}

StringNumConverter::StringNumConverter(string line) : StringNumConverter(line.c_str()){}

StringNumConverter::StringNumConverter(long long int value) {
	inp_str = to_string(value);
}

StringNumConverter::StringNumConverter(double value) {
	inp_str = to_string(value);
}

StringNumConverter::StringNumConverter(const StringNumConverter& other) {
	this->inp_str = other.inp_str;
}

long long int StringNumConverter::getInt() {
	return stoll(inp_str);
}

double StringNumConverter::getDouble() {
	return stod(inp_str);
}

void StringNumConverter::printFormated(std::ostream& cout, unsigned _base, unsigned _fraction)
{
	int digit = StringNumConverter::getDouble();
	string base(to_string(digit));
	string fraction(inp_str.substr(inp_str.find('.') + 1));

	int diff = _base - base.size();
	if (diff < 0) {
		throw exception("Impossible operation");
	}
	else
		while (base.size() < _base)
		{
			base.insert(0, "0");
		}
	

	diff = _fraction - fraction.size();
	if (diff < 0) {
		fraction = fraction.substr(0, fraction.size() + diff);
	}
	else
		while (fraction.size() < _fraction)
		{
			fraction += "0";
		}
	if (_fraction) {
		base += "." + fraction;
	}

	cout << base;
}

StringNumConverter& StringNumConverter::operator+(string str) {
	StringNumConverter snc(*this);
	long double value = stold(str);

	long double value2 = stold(snc.inp_str);
	long double value3 = value + value2;
	snc.inp_str = to_string(value3);
	return snc;
}

bool StringNumConverter::operator==(const StringNumConverter& other) {
	return areEqual(this->inp_str, other.inp_str);
}

bool StringNumConverter::operator!=(const StringNumConverter& other) {
	return !areEqual(this->inp_str, other.inp_str);
}

bool StringNumConverter::operator>(const StringNumConverter& other)
{
	return isGreater(this->inp_str, other.inp_str);
}

bool StringNumConverter::operator<(const StringNumConverter& other)
{
	return !isGreater(this->inp_str, other.inp_str);
}

StringNumConverter::operator long long int() {
	return StringNumConverter::getInt();
}

StringNumConverter::operator double() {
	return StringNumConverter::getDouble();
}

StringNumConverter::operator float() {
	return stof(inp_str);
}
