//C
#include <stdio.h>
#include <string.h>
//C++
#include <iostream>
#include <string>

using namespace std;
int main(void)
{

	string str1 = "Hello";
	string str2 = "World";

	//C++ string 편리
	//str2가 str1보다 사전(dictionary)에 더 늦게 나옴(클 수록 늦게 나옴)--시험
	if (str2 > str1) {
		cout << "str2 > str1";
	}
	else if (str2 < str1) {
		cout << "str2<str1";
	}
	else {
		cout << "str2==str1";
	}
	
	return 0;
}