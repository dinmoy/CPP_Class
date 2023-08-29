#include <iostream>
#include "Animal.h" //따로 지정한 헤더 파일은 <>가 아닌 ""
#include "Shark.h"

using namespace std;



int main(void) 
{
	Animal a ;
	Shark jaws;
	Whale lky;

	a.sing();
	jaws.sing();
	lky.sing();
}