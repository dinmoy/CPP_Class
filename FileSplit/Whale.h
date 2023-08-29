#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;

class Whale : public Animal {
public:
	void sing(void);
private:
	int beard_;
}; 