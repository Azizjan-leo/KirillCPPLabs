// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "date.h"

int main()
{
	Date date1, date2(1995), date3(1995, Date::mar), date4(1995, Date::may, 5);

	////date1 = date2 + date3;    // не должно работать!

	Date tdate1, tdate2;

	tdate1 += 2;

	tdate2++; tdate2++;

	if (tdate1 != tdate2) cout << "Something wrong\n";

	else cout << "As expected\n";

	cout << date1 << endl << date2 << endl << date3 << endl << date4 << endl;

	Date today = Date(2018, Date::sep, 10);

	Date tomorrow = today + 1;
	cout << today;
	Date never = 43 + today;
	//cout << today << never; //Ќе должно работать!

	return 0;
}