#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include <list>
#include "Secretary.h"
#include "Director.h"

int main()
{
    Employee e("Fedya", 1234);
    Manager m("Petya", 1234, 3);
    Secretary s("Kostya", "Livanov", 1234);
    Director d("Misha", "Abuzov");
    list<Employee*> empl;
    std::cout << e.PrintInfo() << "\n";
    std::cout << m.PrintInfo() << "\n";
    std::cout << s.PrintInfo() << "\n";
    std::cout << d.PrintInfo() << "\n";
}