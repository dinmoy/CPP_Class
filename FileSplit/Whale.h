#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;

class Whale : public Animal {
public:
	void sing(void) { cout << "우 우우 우 우" << endl; }
private:
	int beard_;
};