#pragma once

#include<iostream>

namespace space
{
	class string
	{
		const static size_t npos;
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

		void insert(size_t pos, size_t n, char ch)//在pos位置插入n个ch
		{
			size_t end = _size;
			if (_size + n > _capacity)
			{
				reserve((_size + n) * 2);
			}

			if (end >= pos&&end!=npos)
			{
				_str[end + n] = _str[end];
				end--;
			}

			for (size_t i = 0; i < n; i++)
			{
				_str[pos + i] = ch;
			}
			_size += n;
		}

		void insert(size_t pos, const char* str)
		{
			size_t end = _size;
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve((_size + len) * 2);
			}
			if (end >= pos && end != npos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos++] = str[len++];
			}
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			if (len == npos || len > _size - pos)
			{
				_str[pos] = '\0';
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[pos++] = _str[end++];
				}
			}
			_size = pos;
		}
		size_t find(char ch,size_t pos)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
				else
					return npos;
			}
		}

		size_t find(const char* str, size_t pos)
		{
			const char* ptr = strstr(_str + pos, str);
			if (ptr)
			{
				return ptr - _str;
			}
			else
			{
				return npos;
			}
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	const static size_t npos = -1;
}