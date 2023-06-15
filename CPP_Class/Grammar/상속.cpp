#include <iostream>
using namespace std;

#define COLOR_RED	0
#define COLOR_GREEN 1
#define COLOR_BLUE	2

class Animal {
public:
	Animal(int color, int age) : color_(color), age_(age)
	{
		cout << "Animal 생성자()" << endl;
		//cout << age_ << "살" << endl;
		/*switch (color_)
		{
		case COLOR_RED:
			cout << "빨간색" << endl;
			break;
		case COLOR_GREEN:
			cout << "초록색" << endl;
			break;
		case COLOR_BLUE:
			cout << "파란색" << endl;
			break;
		default:
			cout << "이상한 색" << endl;
			break;
		}*/
	}
	virtual ~Animal() { cout << "Animal 소멸자()" << endl; }
	//가상함수 : Java처럼 동적바인딩 + 추상메서드처럼 함수를 정의하지 않음 -> 상소받은 자식에서 정의
	virtual void  Roar(void) = 0;
	virtual void  Eat(void) = 0;
	virtual void Sleep(void) = 0;

private:
	int color_;
	int age_;
};
class Rabbit : public Animal {
public:
	//부모생성자(Animal(color,age))가 먼저 호출
	Rabbit(int color, int age, int ear_length) :Animal(color, age), ear_length_(ear_length)
	{
		cout << "Rabbit 생성자()" << endl;
	}
	virtual ~Rabbit() { cout << "Rabbit 소멸자()" << endl; }
	//함수 override
	//다형ㅅ성(polymorphism): : 시그니쳐(반환형,이름,매개변수가 모두 같은)가 같은 함수임에도 
	//불구하고 다르게 실행되는 것
	//override: 부모 함수 시그니쳐가 존재하지 않으면 에러발생(실수방지)
	void Roar(void) override {
		cout << "깡토깡통" << endl;
	}
	//순수가상함수(추상메서드)는 자식 클래스에서 무조건 정의해야 함
	void Eat(void) override {};
	void Sleep(void) override {};
private:
	int ear_length_;
};
int main() {

	//추상클래스(순수가상함수가 하나라도 존재하는 클래스)의 객체는 생성할 수 없다.
	//Animal a = Animal(COLOR_GREEN, 10);
	//소멸자에 virtual을 안하면 자식소멸자가 호출되지 않아서 메모리 누수현상 발생
	Animal* animal = new Rabbit(COLOR_RED, 3, 20);  //부모의 생성자도 호출
	animal->Roar(); // 깡총깡총
	delete animal;
}