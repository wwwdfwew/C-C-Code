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

//void test_string1()
//{
//	string s1("hello world");
//	/*s1.insert(0, 3, '*');
//	cout << s1.c_str() << endl;
//
//	s1.insert(5, "hello bit");
//	cout << s1.c_str() << endl;*/
//	s1.erase(5,4);
//	cout << s1.c_str() << endl;
//}

void test_string2()
{
		space::string s("https://legacy.cplusplus.com/reference/string/string/");
		size_t pos1 = s.find(':', 0);//从第0位置开始找到':'字符所在位置
		space::string protocol;//协议
		if (pos1 != s.npos)
		{
			protocol = s.substr(0, pos1);//从零开始拷贝pos1长度(也就是https的长度)字符给protocol
		}
		cout << protocol.c_str() << endl;
		//size_t pos2 = s.find('/', (pos1 + 3));//从'l'位置开始找到/所在位置
		//space::string domain;//域名
		//if (pos2 != s.npos)
		//{
		//	domain = s.substr((pos1 + 3), (pos2 - pos1 - 3));//拷贝域名
		//}
		//cout << domain.c_str() << endl;
		//space::string uri = s.substr(pos2 + 1);//拷贝资源，这里直接不给长度，默认是npos，就直接将后面的字符全部拷贝了
		//cout << uri.c_str() << endl;
}

int main()
{
	test_string2();
	return 0;
}