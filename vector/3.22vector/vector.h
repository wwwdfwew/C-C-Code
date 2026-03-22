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

		~vector()
		{
			if (_start)
			{
				delete[] _start;//因为这是数组，开辟了多个空间，所以要用delete[]
				_start = _finish = _end_of_storage = nullptr;
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
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}
				
				_start = tmp;
				_finish = sz + _start;
				_end_of_storage =_start + n;
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}