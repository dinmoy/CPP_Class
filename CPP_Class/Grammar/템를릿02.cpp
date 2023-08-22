#include <iostream>
#include <string.h>

using namespace std;

class Character {
public:
	string  name_;
	int health_;
	int attack_;
	int defence_;

	Character(string name, int health, int attack, int defence)
		:name_(name), health_(health), attack_(attack), defence_(defence)
	{
	}
	void print() {
		cout <<"이름: "<< name_ << endl;
		cout <<"체력: "<< health_ << endl;
		cout <<"공격: "<<attack_ << endl;
		cout <<"방어: "<<defence_ << endl;
	}
};
void main() {
	Character ch("강아지", 100, 20, 10);
	ch.print();
}