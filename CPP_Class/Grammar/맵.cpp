#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) 
{
	map<string, int> moving;

	moving["번개맨"] = 1987;
	moving["장희수"] = 2000;
	moving["봉평"] = 1959;

	map<string, int>::iterator iter;
	for (iter = moving.begin(); iter != moving.end(); iter++) {

	}
}