#pragma once
#include<assert.h>
namespace space
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()//构造函数初始化
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}

		vector(size_t n, const T& val = T())
		{
			resize(n, val);

		}


		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;//因为这是数组，开辟了多个空间，所以要用delete[]
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			reserve(v._end_of_storage);
			for (auto e : v)
			{
				push_back(e);
			}
		}
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _end_of_storage-_start;
		}

		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = val;
			_finish++;
		}

		void reserve(size_t n)
		{
			assert(n > capacity());
			size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				
				_start = tmp;
				_finish = sz + _start;
				_end_of_storage =_start + n;
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		iterator insert(iterator it, const T& val)
		{
			if (it >= _start && it <= _finish)
			{
				if (_finish == _end_of_storage)
				{
					size_t len = it - _start;//记录迭代器和新空间_start的相对位置
					reserve(capacity() == 0 ? 4 : capacity() * 2);


					it = len + _start;//得到新空间迭代器的位置
				}
				iterator end = _finish;
				while (end != it)
				{
					*end = *(end-1);
					end--;
				}
				*it = val;
				++_finish;
			}
			return it;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			
			iterator it = pos;
				while (it!= _finish - 1)
				{
					*it = *(it + 1);
					it++;
				}
				_finish--;
			
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}