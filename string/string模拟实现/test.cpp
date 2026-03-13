#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"string.h"

using namespace std;


int main()
{
	string s("hello world");
	s.push_back('x');
	s.push_back('#');
	s.append("hello bit");
	cout << s << endl;
	return 0;
}