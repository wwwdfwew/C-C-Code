#pragma once

#include<iostream>

namespace space
{
	class string
	{
		typedef char* lterator;
		////有参构造函数
		//string(const char* s)
		//	:_str(new char[strlen(s)])
		//	, _size(strlen(s))
		//	, _capacity(_size)
		//{
		//	strcpy(_str, s);
		//}
		////无参构造函数
		//string()
		//	:_str(new char[1])
		//	, _size(1)
		//	, _capacity(_size)
		//{
		//	_str = '\0';
		//}
		//可以是上面两者的结合
		string(const char* s="")
			:_str(new char[strlen(s)])
			, _size(strlen(s))
			, _capacity(_size)
		{
			strcpy(_str, s);
		}

		char* c_str()
		{
			return _str;
		}

		size_t size()
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}

		lterator begin()
		{
			return _str;
		}

		lterator end()
		{
			return _str + _size;
		}

		void reserve(size_t n)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;//这里销毁的是_str指向的那个动态开辟的空间，并不是_str这个空间
			_str = tmp;
			_capacity += n + 1;
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size] = 'ch';
			_size += 1;
			_str[_size + 1] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if ((_size + len) > _capacity)
			{
				reserve(_capacity == 0?4: _capacity * 2);//这是因为可能字符串为空，所以长度为0,容量也为0
			}
			strcpy(_str + _size, str);
			_size += len;
			_str[_size] = '\0';
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}