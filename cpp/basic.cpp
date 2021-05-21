#include <iostream>
using namespace std;

class Employee
{
public:
    string Name, Company;
    int Age;

    void Introduction()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee employee1 = Employee("Ankit", "AWS", 23);
    Employee employee2 = Employee("John", "Amazon", 25);

    employee1.Introduction();
    employee2.Introduction();

    return 0;
}