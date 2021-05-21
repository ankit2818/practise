// most common use of polymorphism is when a parent class reference is used to refer to child class object

#include <iostream>
using namespace std;

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
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
    void AskForPromotion()
    {
        if (Age > 30)
        {
            cout << Name << " got promoted" << endl;
        }
        else
        {
            cout << Name << " not promoted" << endl;
        }
    };

    virtual void Work()
    {
        cout << Name << " is checking email, task backlog" << endl;
    };
};

// child class : parent class
class Developer : Employee
{
public:
    string FavProgrammingLanguage;

    Developer(string name, string company, int age, string favprogramminglanguage) : Employee(name, company, age)
    {
        FavProgrammingLanguage = favprogramminglanguage;
    }

    void FixBug()
    {
        cout << getName() << " fixed bug using " << FavProgrammingLanguage << endl;
    };
};

// child class : parent class
class Coder : public Employee
{
public:
    string FavProgrammingLanguage;

    Coder(string name, string company, int age, string favprogramminglanguage) : Employee(name, company, age)
    {
        FavProgrammingLanguage = favprogramminglanguage;
    }

    void FixBug()
    {
        cout << getName() << " fixed bug using " << FavProgrammingLanguage << endl;
    };

    void Work()
    {
        cout << getName() << " is writing code in " << FavProgrammingLanguage << endl;
    };
};
// child class : parent class
class Teacher : public Employee
{
public:
    string Subject;

    void PrepareLesson()
    {
        cout << getName() << " is preparing " << Subject << " lesson" << endl;
    };
    Teacher(string name, string company, int age, string subject) : Employee(name, company, age)
    {
        Subject = subject;
    }

    void Work()
    {
        cout << getName() << " is teaching " << Subject << endl;
    };
};

int main()
{
    Developer d = Developer("Deveoper", "AWS", 20, "cpp");
    Coder c = Coder("Coder", "Google", 30, "python");
    Teacher t = Teacher("Teacher", "Amazon", 35, "Maths");

    // // d.Work(); // not accesible
    // c.Work();
    // t.Work();

    // Employee *e1 = &d; // not accesible
    Employee *e2 = &c;
    Employee *e3 = &t;

    e2->Work();
    e3->Work();

    return 0;
}