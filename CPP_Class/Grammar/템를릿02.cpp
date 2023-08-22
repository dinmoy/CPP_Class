#include <iostream>
#include <string.h>

using namespace std;
template <typename T>

class Character {
public:
	string  name_;
	T health_;
	T attack_;
	T defence_;

	Character(string name, T health, T attack, T defence)
		:name_(name), health_(health), attack_(attack), defence_(defence)
	{
	}
	void print() {
		cout << "이름: " << name_ << endl;
		cout << "체력: " << health_ << endl;
		cout << "공격: " << attack_ << endl;
		cout << "방어: " << defence_ << endl;
	}
};
void main() {
	Character<int>* ch=new Character<int>("강아지", 100, 20, 10);
	ch->print();
	delete ch;
}