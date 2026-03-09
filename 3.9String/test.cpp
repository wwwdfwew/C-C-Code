#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] ;
//	}
//	cout << endl;
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it ;
//		it++;
//	}
//	cout << endl;
//	return 0;
//}

int main()
{
	string s1("hello world");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	return 0;
}