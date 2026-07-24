#include<iostream>

using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "姓名：" << name << endl;
		cout << "年龄：" << age << endl;

	}
public:
	string name = "姓名";
	int age = 18;
};

class Student :public Person
{
private:
	string stuid;//学号
};

int main()
{
	Student st;
	return 0;
}