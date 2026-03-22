#include<iostream>
#include"vector.h"
using namespace std;

void test_vector1()
{
	space::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	for (auto e : v)
	{
		cout << e << " ";
	}
}
int main()
{
	test_vector1();
	return 0;
}