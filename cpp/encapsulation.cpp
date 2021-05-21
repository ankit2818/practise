#include <iostream>
using namespace std;

class Employee
{
private:
    string Name, Company;
    int Age;

public:
    // Setters
    void setName(string name)
    {
        Name = name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    void setAge(int age)
    {
        if (age >= 18)
        {
            Age = age;
        }
    }
    // Getters
    string getName()
    {
        return Name;
    }
    string getCompany()
    {
        return Company;
    }
    int getAge()
    {
        return Age;
    }
    // Methods
    void Introduction()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    // Constructor
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