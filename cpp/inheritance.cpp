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
};

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
};

int main()
{
    Employee employee1 = Employee("Ankit", "AWS", 23);
    Employee employee2 = Employee("John", "Amazon", 35);

    // employee1.Introduction();
    // employee2.Introduction();
    // employee1.AskForPromotion();
    // employee2.AskForPromotion();

    // Developer dev = Developer("Ankit", "AWS", 25, "cpp");
    // dev.FixBug();
    // // dev.AskForPromotion(); // Not accesible

    // Coder cod = Coder("Ankit", "AWS", 25, "cpp");
    // cod.AskForPromotion(); // accesible

    Teacher t = Teacher("Ankit", "Amazon", 35, "Maths");
    t.PrepareLesson();
    t.AskForPromotion();
    return 0;
}