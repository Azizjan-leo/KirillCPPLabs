// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include "StringNumConverter.h"

using namespace std;

int main()
{
	bool i = true;
	do{
		string num1, num2;
		
		cout << "Input the first number: ";
		cin >> num1;
		cout << "Input the second number: ";
		cin >> num2;

		StringNumConverter obj1(num1), obj2("0");
		
		obj2 = obj1 + num2;

		
		cout << "The first number: " << obj1 << endl;
		
		cout << "The second number: " << obj2 << endl;

	} while (i);
//	StringNumConverter a;//не должно работать

	StringNumConverter b("-12063959085888582858005028580285808509859590");
	/*9223372036854775807*/
	StringNumConverter c(1e-1);

	StringNumConverter d(1.2);

	if (d != StringNumConverter((float)c + 1.1)) cout << "Something wrong\n";

	else cout << "As expected\n";

	cout << b + "9" << endl << c + "1" << endl;

	double asd = b.getDouble();
	cout << asd;

	return 0;
}