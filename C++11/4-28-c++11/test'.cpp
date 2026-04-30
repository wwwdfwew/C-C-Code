#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;
#include"vector.h"
//struct Point
//{
//	Point(int x,int y)
//		:_x(x),
//		_y(y)
//	{
//
//	}
//private:
//	int _x;
//	int _y;
//};
//
//int main()
//{
//	//C++11写法：
//	int a = { 10 };
//	int b{ 20 };
//	//对于结构体：
//	Point p = { 10,20 };
//	//对于数组：
//	int arr[10]{ 1,2,3,4,5,6 };
//	
//	auto c = { 30 };
//	cout << typeid(c).name() << endl;
//
//	return 0;
//}



//int main()
//{	
//	//形参为initializer_list的构造函数
//	bit::vector<int> v = { 1,2,3,4,5,6 };
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	//auto p1 = 10;
//	//////无法直接定义，必须先推导出p2的类型，再去运算
//	////auto p2 = p1;
//	////p2 = 20;
//	////cout << typeid(p1).name() << endl;
//	////cout << typeid(p2).name() << endl;
//	//decltype(p1) p2 = 20;
//
//
//	int a = 10;
//	int b = 20;
//	auto p = a + b;
//	cout << typeid(p).name() << endl;
//	return 0;
//}

// string func(const string& s )
//{
//	 string str=s;
//	cout << str << endl;
//	return str;
//}
//
//int main()
//{
//	////a为左值，20为右值
//	//int a = 20;
//	////左值引用
//	//int& p = a;
//	int a = 10;
//	int b = 20;
//	//右值引用
//	int&& c = a + b;
//	string&& ret = func("xxxxxxxxxxxxxxxxxxxxx");
//	return 0;
//}

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		
		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}

		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- " << endl;
			
			swap(s);
		}
		// 赋值重载
		string& operator=(const string& s)
		{

			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		
		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动语义" << endl;
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};
}


//拷贝构造右值引用的应用(函数调用)

bit::string func()
{
	bit::string str("xxxxxxxxxxxxx");
	return str;
}

int main()
{
	//bit::string s=func();//拷贝构造
	bit::string s;
	s = func();
	return 0;
}


