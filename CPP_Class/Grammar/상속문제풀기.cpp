#include <iostream>
using namespace std;

class Person {
public:
	string name_;
	int hakbun_;
public:
	Person(string name, int hakbun) : name_(name), hakbun_(hakbun) {
	}
	void PrintShow(void) { cout << "이름:" << name_ << " 학번:" << hakbun_ << endl; }
	
	

};
class Student : public Person {
private:
	string university_;

public:
	Student(string name, int hakbun, string university) : Person(name,hakbun), university_(university) {
	}
	void PrintShow(void) {
		cout << "이름:" << name_ << " 학번:" << hakbun_ << " 학교:" << university_ << endl;
	}
};

int main() {
	Person* person = new Person("효지니", 2117);
	person->PrintShow();
	Student* stu = new Student("임효진", 1217, "미림");
	stu->PrintShow();
	
	delete stu;
	delete person;

	
}