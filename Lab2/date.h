#pragma once
#include <iostream>
#include <ostream>
#include <map>
using namespace std;

class Date {
public:
	enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
private:
	int day;
	int month;
	int year;
	static const int static_day = 27;
	static const int static_month = Date::may;
	static const int static_year = 1234;
public:
	Date(int _year = static_year, int _month = static_month, int _day = static_day) : year(_year), month(_month), day(_day)  {};
	Date(const Date&);
	void addDay(int);
	void addMonth(int);
	void addYear(int);
	Date& operator = (const Date&);
	Date& operator ++ ();
	Date& operator ++ (int);
	Date& operator -- ();
	Date& operator -- (int);
	bool operator == (const Date&);
	bool operator != (const Date&);
	bool operator > (const Date&);
	bool operator < (const Date&);
	Date operator + (int);
	friend Date operator + (int, Date&);
	Date operator - (int);
	Date& operator += (int);
	Date& operator -= (int);
	friend ostream& operator << (ostream& os, const Date& other);
	friend istream& operator >> (istream& is, Date& other);
	const int getMonth();
	const int getYear();
	const int getDay();
};