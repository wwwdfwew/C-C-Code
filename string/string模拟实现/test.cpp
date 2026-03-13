#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"string.h"

using namespace std;


//int main()
//{
//	/*string s("hello world");
//	s.push_back('x');
//	s.push_back('#');
//	s.append("hello bit");
//	cout << s << endl;*/
//	return 0;
//}

void test_string1()
{
	string s1("hello world");
	/*s1.insert(0, 3, '*');
	cout << s1.c_str() << endl;

	s1.insert(5, "hello bit");
	cout << s1.c_str() << endl;*/
	s1.erase(5,4);
	cout << s1.c_str() << endl;
}

int main()
{
	test_string1();
	return 0;
}