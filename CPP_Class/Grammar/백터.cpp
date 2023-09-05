﻿#include <iostream>
#include <vector>

using namespace std;

int main(void) 
{
	//전통적인 배열은 크기가 고정되어있으나 
	//백터는 크기가 자유롭게 변할 수 있는 동적배열
	vector<int> arr;
	int *arr = new int[4];
	arr.reserve(4);   //백터의 크기를 4로 한다
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);

	// 4개가 꽉 찬 공간에 데이터 하나를 더 집어넣어보자
	arr.push_back(50);

	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	 
}