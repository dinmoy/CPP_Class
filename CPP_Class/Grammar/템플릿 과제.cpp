#include <iostream>

using namespace std;

template <typename T>

T sum(T a, T b)
{
	T z = a + b;
	return z;
}
int main() {
	cout << sum<int>(3, 5) << endl;
	cout << sum<double>(4.f, 6.f) << endl;
}