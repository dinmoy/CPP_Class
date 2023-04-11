﻿#include <iostream>
#include <string>

using namespace std;

//여러 data들을 하나의 의미있는 구조체로 묶어서 관리
//구조체,클래스는 일반적으로 단어의 첫 글자를 대문자로 한다
//class는 default가 private(struct는 default가 public)--시험
class Student {

public:
    //생성자(constructor) : 객체가 생성될 때 호출되는 함수
    // 생성자 함수의 이름은 클래스명과 같다 
    // 생성자는 반환형이 없다
    //생성자를 정의하지 않으면 자동(default)으로 매개변수가 없는 생성자가 정의된다
    //Student(){ }
    Student() {
        name = "임효진";
        student_num = 2117;
        age = 18;
        gender = 1;
        department = "소프트웨어과";

    }

    // : 멤버변수 초기화를 하면 const멤버변수도 초기화 할 수 있다
    Student(string _name, int _student_num, int _age, int _gender, string _department)
        :name(_name), student_num(_student_num), age(_age)
        , gender(_gender), department(_department)
    {
    }

    //Student(string _name, int _student_num, int _age, int _gender, string _department)
    //{

    //    //this : 객체 자기자신을 가리키는 포인터
    //    //매개변수명과 멤버변수명이 같아도 구별 가능
    //    this->name = name;
    //    this->student_num = student_num;
    //    this->age = age;
    //    this->gender = gender;
    //    this->department = department;
    //}
    //class는 멤버변수를 가질 수 있다--멤버함수
    void print(void)
    {
        cout << "이름: " << name << endl;
        cout << "학번: " << student_num << endl;
        cout << "나이: " << age << endl;
        cout << "성별(0)남자,(1)여자: " << gender << endl;
        cout << "학번: " << department << endl;
    }
    void set_name(string _name) { name = _name; }
    void set_hakbun(int _student_num) { student_num = _student_num; }
    void set_age(int _age) { age = _age; }
    void set_gender(int _gender) { gender = _gender; }
    void set_department(string _department) { department = _department; }
private:
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
    
    //정적할당 : 메모리의 크기가 컴파일할 때 결정됨
    //Student stu1 = Student("임효진", 2117, 18, 1, "뉴미디어 소프트웨어과");
    //stu1.print();

    /*Student stu3[2];
    for (int i = 0; i < 2; i++) {
        stu3[i].print();
    }*/

    //동적할당 : 메모리의 크기가 실행할 때(runtime)  결정됨. heap영역
    // C++의 동적할당은 반드시 delete로 해제해야 메모리 누수를 막을 수 있음
    //Student* stu2 = new Student("서강준",3100,31,0,"방송연예과");
    //stu2->print();    // 단일객체는 멤버를 -> 로 접근
    Student* stu4 = new Student[2];
    stu4[0].set_age(18);
    stu4[0].set_name("지수");
    stu4[0].set_hakbun(2112);
    stu4[0].set_gender(1);
    stu4[0].set_department("뉴미디어 소프트웨어과");

    stu4[1].set_age(18);
    stu4[1].set_name("혁수");
    stu4[1].set_hakbun(2118);
    stu4[1].set_gender(0);
    stu4[1].set_department("뉴미디어 소프트웨어과");

    for (int i = 0; i < 2; i++) 
        stu4[i].print(); //배열의 요소에 해당하는 객체는 멤버를 .으로 접근
    delete[] stu4;
   
   

    


   // delete stu2;


    return 0;
}
