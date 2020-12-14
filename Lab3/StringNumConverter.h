#pragma once
#include <iostream>
#include <string>

using namespace std;

class StringNumConverter {
private:
	string inp_str;
	bool areEqual(string firstNum, string secondNum);
	bool isGreater(string firstNum, string secondNum);
public:
	StringNumConverter(const char* line = "0");
	StringNumConverter(string line = "0");
	StringNumConverter(long long int);
	StringNumConverter(double);
	StringNumConverter(const StringNumConverter&);
	StringNumConverter() = delete;
	long long int getInt();
	double getDouble();
	void printFormated(std::ostream&, unsigned, unsigned);
	StringNumConverter& operator + (string);
	bool operator == (const StringNumConverter&);
	bool operator != (const StringNumConverter&);
	bool operator > (const StringNumConverter&);
	bool operator < (const StringNumConverter&);
	operator long long int();
	operator double();
	operator float();

	friend ostream& operator << (ostream&, const StringNumConverter&);
};
