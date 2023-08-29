#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;

class Shark : public Animal {
public:
	void sing(void);
private:
	int teeth_;
};