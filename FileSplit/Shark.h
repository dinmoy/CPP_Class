#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;

class Shark : public Animal {
public:
	void sing(void) { cout << "아기상어 뚜두뚜두" << endl; }
private:
	int teeth_;
};