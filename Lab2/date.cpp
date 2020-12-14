#include "date.h"

Date operator + (int value, Date& other) {
	other.addDay(value);
	return other;
}

Date& Date::operator++() {
	addDay(1);
	return *this;
}

Date& Date::operator++(int value) {
	addDay(1);
	return *this;
}

Date& Date::operator--() {
	addDay(-1);
	return *this;
}

Date& Date::operator--(int value) {
	addDay(-1);
	return *this;
}

bool Date::operator==(const Date& other) {
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::operator!=(const Date& other) {
	return !(this->day == other.day && this->month == other.month && this->year == other.year);
}

bool Date::operator>(const Date& other) {
	if (this->year < other.year) return false;
	if (this->year == other.year && this->month < other.month) return false;
	if (this->year == other.year && this->month == other.month && this->day < other.day) return false;
	return true;
}

bool Date::operator<(const Date& other) {
	if (this->year > other.year) return false;
	if (this->year == other.year && this->month > other.month) return false;
	if (this->year == other.year && this->month == other.month && this->day > other.day) return false;
	return true;
}

Date Date::operator+(int value) {
	Date d(*this);
	d.addDay(value);
	return d;
}

Date Date::operator-(int value) {
	addDay(-value);
	return *this;
}

Date& Date::operator+=(int value) {
	addDay(value);
	return *this;
}

Date& Date::operator-=(int value) {
	addDay(-value);
	return *this;
}

const int Date::getMonth() {
	return month;
}

const int Date::getYear() {
	return year;
}

const int Date::getDay() {
	return day;
}

ostream& operator << (ostream& os, const Date& other) {
	os << "Date: " << other.day << "." << other.month << "." << other.year << endl;
	return os;
}

istream& operator >> (istream& is, Date& other) {
	cout << "Enter the year: ";
	is >> other.year;
	cout << "Enter the month: ";
	is >> other.month;
	while (other.month > 11 && other.month < 0) {
		cout << "Incorrect month. Please try again:\n";
		is >> other.month;
	}
	cout << "Enter the day: ";
	is >> other.day;
	while (other.day > 32 && other.day < 1) {
		cout << "Incorrect day. Please try again:\n";
		is >> other.day;
	}
	return is;
}

Date::Date(const Date& other) {
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

void Date::addDay(int increment) {

	map<int, int> monthBase = {
	{Date::jan, 31 },
	{Date::feb, year % 4 == 0 ? 29 : 28},
	{Date::mar, 31},
	{Date::apr, 30},
	{Date::may, 31},
	{Date::jun, 30},
	{Date::jul, 31},
	{Date::aug, 31},
	{Date::sep, 30},
	{Date::oct, 31},
	{Date::nov, 30},
	{Date::dec, 31}
	};

	if (increment >= 0) {
		day += increment;
		while (day > monthBase.find(month)->second) {
			day -= monthBase.find(month)->second;
			addMonth(1);
		}
	}
	else {
		day += increment;
		while (day < 1) {
			day += monthBase.find(month)->second;
			addMonth(-1);
		}
	}

}

void Date::addMonth(int increment) {
	month += increment;
	while (month > 11) {
		year++;
		month -= 12;
	}
	while (month < 1) {
		year--;
		month += 12;
	}
}

void Date::addYear(int increment) {
	year += increment;
}

Date& Date::operator=(const Date& other) {
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	return *this;
}