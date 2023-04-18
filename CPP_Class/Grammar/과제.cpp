#include <iostream>
#include <string>

using namespace std;

class Employee {

private:
    string name;
    int id;
    int age;
    double salary;

public:

    Employee() {
    }
    Employee(string _name, int _id, int _age, double _salary)
        :name(_name), id(_id), age(_age), salary(_salary)
    {
    }

    void PrintInfo(void) {
        cout << "이름:" << name << endl;
        cout << "사번:" << id << endl;
        cout << "나이:" << age << endl;
        cout << "급여:" << salary << endl;
    }
    void set_name(string _name) { name = _name; };
    void set_id(int _id) { id = _id; };
    void set_age(int _age) { age = _age; };
    void set_salary(double _salary) { salary = _salary; };
};

int main() {
    Employee p1 = Employee("효지니", 1111, 18, 500000);
    p1.PrintInfo();
    printf("\n");

    Employee* p2 = new Employee("지우쌤",5050, 31, 700000);
    p2->PrintInfo();
    printf("\n");

    Employee* p3 = new Employee[2];
    p3[0].set_name("정선영");
    p3[0].set_id(1234);
    p3[0].set_age(17);
    p3[0].set_salary(500000);
     
    p3[1].set_name("이지수");
    p3[1].set_id(1222);
    p3[1].set_age(27);
    p3[1].set_salary(400000);

    for (int i = 0; i < 2; i++) {
        p3[i].PrintInfo();
        printf("\n");
    }
    delete[] p3;

    return 0;


}


