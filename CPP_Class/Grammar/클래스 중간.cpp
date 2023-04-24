#include <iostream>
 
using namespace std;

class MString {
public:
	MString(const char* str) 
	{
		unsigned int str_length = strlen(str);
		//필요한 길이만큼 문자열 동적할당
		c_str_ = new char[str_length+1];  //'/0' (널문자) 공간 +1
		strcpy(c_str_, str);
	}
	//소멸자(destructor)
	~MString() 
	{
		//생성자에서 동적할당한 공간을 해제
		delete[] c_str_;
	}
	unsigned int size() { return size_; }
    char* c_str() { return c_str_;  }
	void print() {
		cout << c_str_ << endl;
	}
private:
	unsigned int size_;	  //문자열의 길이
	char* c_str_; //문자열을 가리키는 주소

};
int main(void)
{

	//new로 동적할당한 공간은 반드시 delete로 해제시켜야함
	//만약 그렇지 않으면 메모리가 누수됨
	MString* str = new MString("강아지 뇽뇽");
	cout << str->c_str() << endl;
	//str에 대한 delete는 진행 되었으나, str->c_str에 대한 delete가 진행되지 않음
	//TODO: 이를 delete해주는 소멸자(destructor)구현하기
	delete str;





	return 0;
}