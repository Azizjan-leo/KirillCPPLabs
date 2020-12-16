#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include <list>
#include "Secretary.h"
#include "Director.h"
#include "Tsec.h"
#include "Consultant.h"
#include <fstream>


void print_list(list<Employee*> employees);

int main()
{
    Temporary t("Andrusha", "Avdeev");
    Employee e("Fedya", 1234);
    Manager m("Petya", 1234, 3);
    Secretary s("Kostya", "Livanov", 1234);
    Director d("Misha", "Abuzov");
    Tsec ts("Danya", "Kuznetsov", 1234);
    Consultant c("Masha", "Petrenko");
    list<Employee*> empl;
    empl.push_front(&e);
    empl.push_front(&ts);
    empl.push_back(&s);
    empl.push_back(&m);
    empl.push_back(&d);

    std::cout << "Employees!" << "\n";
    print_list(empl);
    std::cout << "Unemployed!" << "\n";
    std::cout << t.PrintInfo() << "\n\n";
    std::cout << c.PrintInfo() << "\n\n";

    std::cout << "Total!\n";
    std::cout << "Temporaries: " + to_string(Temporary::GetCount()) << "\n";
    std::cout << "Employees: " + to_string(Employee::GetCount()) << "\n";
    std::cout << "Managers: " + to_string(Manager::GetCount()) << "\n";
    std::cout << "Secretaries: " + to_string(Secretary::GetCount()) << "\n";
    std::cout << "Directors: " + to_string(Director::GetCount()) << "\n";
    std::cout << "Temp. secretaries: " + to_string(Tsec::GetCount()) << "\n";
    std::cout << "Consultants: " + to_string(Consultant::GetCount()) << "\n\n";

    ifstream source("Source.txt");

    list<unique_ptr<Employee>> employees;
    if (source.good())
    {
        while (!source.eof())
        {
            Employee esa(source);
            employees.emplace_back(make_unique<Employee>(esa));
        }
    }
    for (auto& emp : employees) {
        std::cout << emp->PrintInfo() << "\n\n";
    }
}

void print_list(list<Employee*> employees) {
    for (auto& emp : employees) {
        std::cout << emp->PrintInfo() << "\n\n";
    }
}