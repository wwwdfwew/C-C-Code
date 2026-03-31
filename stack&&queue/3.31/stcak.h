#pragma once
namespace space
{
	template<class T,class Container>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		
		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			/*int n = _con.size() - 1;
			return _con[n];*/
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}