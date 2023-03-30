#include <iostream>
#include <string>

using namespace std;

//여러 data들을 하나의 의미있는 구조체로 묶어서 관리
//구조체,클래스는 일반적으로 단어의 첫 글자를 대문자로 한다
//class는 default가 private(struct는 default가 public)--시험
class Student {
public:
    string name;
    //시험X: 학번을 성능때문에 뮨자열로 하지 않음
    //일반적으로 문자열은 정수데이터보다 많은 메모리 공간을 요구하며
    //정수는 비교연산을 한번에 할 수 있으나, 문자열은 글자 수 만큼 반복하여 비교해야함
    int student_num;
    int age;
    //가독성과 유지보수를 위해 열거형(enum)으로 하는 것을 추천
    //0:남자 1:여자
    int gender; 
    string department;
};

int main() {
    
    //(struct drink)자료형(C++에서는 drink만 써도  됨)/struct 자체가 자료형
    struct Student stu1;
    stu1.name = "임효진";
    stu1.student_num = 2117;
    stu1.age = 18;
    stu1.gender = 1;
    stu1.department = "소프트웨어과";

    cout << "이름: " << stu1.name << endl;
    cout << "학번: " << stu1.student_num << endl;
    cout << "나이: " << stu1.age << endl;
    cout << "성별(0)남자,(1)여자: " << stu1.gender<< endl;
    cout << "학번: " << stu1.department << endl;
    return 0;
}
