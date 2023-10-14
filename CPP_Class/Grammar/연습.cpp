#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	
	/*map<string, string> pet;

	pet["강아지"] = "말티즈";
	pet["고양이"] = "페르시안";
	pet["여  우"] = "북극여우";

	map<string, string>::iterator iter;

	for (iter = pet.begin(); iter != pet.end(); iter++) {
		cout << iter->first <<"  "<< iter->second << endl;
	}*/

	vector<string>pet;
	pet.reserve(4);
	pet.push_back("강아지");
	pet.push_back("고양이");
	pet.push_back("햄스터");
	pet.push_back("여우");

	vector<string>::iterator iter;
	for (iter = pet.begin(); iter != pet.end(); iter++) {
		cout <<*iter << endl;
	}
	    
}