#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include"string.h"

using namespace std;


//int main()
//{
//	space::string s("hello world");
//	s.push_back('x');
//	s.push_back('#');
//	s.append("hello bit");
//	cout << s.c_str() << endl;
//	return 0;
//}

//void test_string1()
//{
//	space::string s1("hello world");
//	/*s1.insert(0, 3, '*');
//	cout << s1.c_str() << endl;*/
//
//	s1.insert(5, "hello bit");
//	cout << s1.c_str() << endl;
//	/*s1.erase(5,4);
//	cout << s1.c_str() << endl;*/
//}

//void test_string2()
//{
//		space::string s("https://legacy.cplusplus.com/reference/string/string/");
//		size_t pos1 = s.find(':', 0);//从第0位置开始找到':'字符所在位置
//		space::string protocol;//协议
//		if (pos1 != space::string::npos)
//		{
//			protocol = s.substr(0, pos1);//从零开始拷贝pos1长度(也就是https的长度)字符给protocol
//		}
//		cout << protocol.c_str() << endl;
//		size_t pos2 = s.find('/', (pos1 + 3));//从'l'位置开始找到/所在位置
//		space::string domain;//域名
//		if (pos2 != s.npos)
//		{
//			domain = s.substr((pos1 + 3), (pos2 - pos1 - 3));//拷贝域名
//		}
//		cout << domain.c_str() << endl;
//		space::string uri = s.substr(pos2 + 1);//拷贝资源，这里直接不给长度，默认是npos，就直接将后面的字符全部拷贝了
//		cout << uri.c_str() << endl;
//}

//void test_string3()
//{
//	space::string s("hello world");
//	s.resize(8);
//	cout << s.c_str() << endl;
//}
//void test_string4()
//{
//	space::string s("hello world");
//	cout << s << endl;
//	cout << s.c_str() << endl;
//
//	s += '\0';
//	s += "!!!!!!!!";
//	cout << s.c_str() << endl;
//	cout << s << endl;
//
//	space::string copy(s);
//	cout << s << endl;
//	cout << copy << endl;
//	/*s += "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
//	cout << s << endl;*/
//}

//void test_string5()
//{
//	space::string s;
//	cin >> s;
//	cout << s << endl;
//	cin >> s;
//	cout << s << endl;
//}

//void test_string6()
//{
//	/*space::string s1("hello world");
//	space::string s2;
//	s2 = s1;
//	cout << s1 << endl;
//	cout << s2 << endl;*/
//
//	space::string s1("hello world");
//	space::string s2("xxxxxxxxxxxxxxxxxx");
//	s1 = s2;
//	cout << s1 << endl;
//	cout << s2 << endl;
//
//}

void test_string7()
{
	space::string s1("hello");
	space::string s2("helloyyy");
	cout << (s1 < s2) << endl;
}
int main()
{
	test_string7();
	return 0;
}