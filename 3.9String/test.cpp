#include<iostream>
#include<string>
#include <list>
#include <vector>
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

//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//	return 0;
//}
//void Func(const string& s)
//{
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	string s1("hello world");
//	Func(s1);
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	string::reverse_iterator it = s1.rbegin();
//	while (it != s1.rend())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	for (auto e : s1)
//	{
//		cout << e<<" ";
//	}
//	cout << endl;
// reverse(s1.rbegin(), s1.rend());
//cout << s1;
//	return 0;
//}
//
//
//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	for (auto e : s1)
//	{
//		e++;
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << s1;
//	return 0;
//}

//#include <list>
//#include <vector>
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	list<int> lt;
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	list<int>::iterator lit = lt.begin();
//	while (lit != lt.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//}

//
//int main()
//{
//	string s1("hello world");
//	string::reverse_iterator it = s1.rbegin();
//	while (it != s1.rend())
//	{
//		cout << *it;
//		it++;
//	}
//
//	cout << endl;
//	reverse(s1.rbegin(), s1.rend());
//	cout << s1;
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	for (auto e : s1)
//	{
//		cout << e<<" ";
//	}
//	cout << endl;
// reverse(s1.begin(), s1.end());
//cout << s1;
//	return 0;
//}

//
//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//
//	return 0;
//}


//
//int main()
//{
//	string s1("hello world");
//	size_t old = s1.capacity();
//	cout << s1.capacity() << endl;;
//	for (size_t i = 0; i < 100; i++)
//	{
//		s1 += '0' + 1;
//		if (old != s1.capacity())
//		{
//			cout <<"空间总大小：" << s1.capacity() << endl;
//			old = s1.capacity();
//		}
//	}
//	return 0;
//}



//int main()
//{
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//
//	char s2[] = { "hello world" };
//
//	s1[1]++;//s1.operator[](1)
//	s2[1]++;//*(s2+1)
//	return 0;
//}


int main()
{
	string s1("hello world");
	string::iterator it = s1.begin();
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}