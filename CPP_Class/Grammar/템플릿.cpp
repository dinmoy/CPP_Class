#include <iostream>
using namespace std;

template <typename T>

T sum(T a, T b)
{
	return a + b;
}
string sum(string a, string b) {
	return a + b;
}
int main(void) {
	cout << sum<int>(1, 2) << endl;
	cout << sum<double>(1.f, 2.f) << endl;
	cout << sum<string>("1", "2") << endl;
}