#pragma once

//#include<iostream>


namespace space
{
	class string
	{
	public:
		 const static size_t npos;
		typedef char* lterator;
		////有参构造函数
		//string(const char* s)
		//	:_str(new char[strlen(s)+1])
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
		{
			_size=strlen(s);
			_capacity=_size + 1;
			_str = new char[_capacity + 1];
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

		const char& operator[](size_t pos)const
		{
			return _str[pos];
		}

		const lterator begin()const
		{
			return _str;
		}

		const lterator end()const
		{
			return _str + _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				std::cout << "reserve->" << n << std::endl;
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);//这是因为可能字符串为空，所以长度为0,容量也为0
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if ((_size + len) > _capacity)
			{
				reserve(_size+len);
			}
			strcpy(_str + _size, str);
			_size += len;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void insert(size_t pos, size_t n, char ch)//在pos位置插入n个ch
		{
			size_t end = _size;
			if (_size + n > _capacity)
			{
				reserve((_size + n) * 2);
			}

			while (end!= npos&&end >= pos)
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
			while (end != npos&&end >= pos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos++] = str[i];
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
			}
			return npos;
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

		string substr(size_t pos, size_t len = npos)
		{
			size_t n = len;
			if ( len == npos || pos + len > _size)
			{
				n = _size - pos;
			}
			string tmp;
			tmp.reserve(n);
			for (size_t i = pos;i < (n + pos);i++)
			{
				tmp.push_back(_str[i]);
			}

			return tmp;
		}


		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;

		}
		
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
			}
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	/*ostream& operator<<(ostream& out, const string& s)
	{
		
		for (auto ch : s)
		{
			out << s;
		}
		return out;
	}*/

std::ostream& operator<< (std::ostream& out, const string& s)
	{
		/*for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}*/

		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	std::istream& operator>>(std::istream& in,  string& s)
	{
		s.clear();
		char ch = in.get();//将空格和换行符也读取
		while (ch == ' ' || ch == '\n')//清理空格和换行符
		{
			ch = in.get();
		}

		//开辟一个char类型的数组，当空间满了或者遇到空格/换行符时才进行添加
		//这样可以减少扩容次数
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)//当空间满时添加
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)//遇到空格或者换行符时添加
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}


//std::istream& operator>>(std::istream& in, string& s)
//{
//	s.clear();
//	char ch = in.get();
//	while (ch == ' ' || ch == '\n')//清理空格和换行符
//	{
//		ch = in.get();
//	}
//	while (ch != ' ' && ch != '\n')
//	{
//		s += ch;
//		ch = in.get();
//	}
//	return in;
//
//}
	const size_t string:: npos = -1;
}