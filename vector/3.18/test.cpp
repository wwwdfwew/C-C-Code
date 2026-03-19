#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//int main()
//{
//	vector<int> vt;
//	vt.push_back(1);
//	vt.push_back(2);
//	vt.push_back(3);
//	vt.push_back(4);
//
//	for (int i = 0; i < vt.size(); i++)
//	{
//		cout << vt[i] << " ";
//	}
//	cout << endl;
//	vector<int>::iterator it = vt.begin();
//	while (it != vt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	for (auto e : vt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//void test_vector1()
//{
//	vector<int> v1;//默认构造
//	vector<int> v2(10, 1);//用10个1初始化
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	vector<char> v3(10, 'x');//用十个字符x初始化
//	for (auto e : v3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	vector<string> v4(10, "xxx");//用十个字符串xxx初始化
//	for (auto e : v4)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	string s("hello world");
//	vector<char>v5(s.begin(), s.end());//迭代器区间初始化
//	for (auto e : v5)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int>v6(3, 'x');
//	for (auto e : v6)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//int a[] = { 1,3,16,20 };
//vector<int> v1(a, a + 4);
//}

//void test_vector2()
//{
//	/*int a[] = { 24,18,31,20 };
//	vector<int> v1(a, a + 4);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	sort(v1.begin(), v1.end());
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;*/
//
//	int a[] = { 24,18,31,20 };
//	vector<int> v1(a, a + 4);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	greater<int> gt;//控制降序
//	sort(v1.begin(), v1.end(),gt);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	less<int> ls;//控制升序
//	sort(v1.begin(), v1.end(), ls);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//void test_vector3()
//{
//	vector<int> v1;
//	//v1.reserve(5);
//	v1.resize(5);
//	for (size_t i = 0; i < 5; i++)
//	{
//		v1[i] = i;
//	}
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int> v1;
//	v1.reserve(5);
//	for (size_t i = 0; i < 5; i++)
//	{
//		v1.push_back(i);
//	}
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}

void test_vector4()
{

}
int main()
{
	test_vector4();
	return 0;
}