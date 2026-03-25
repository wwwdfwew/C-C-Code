#pragma once

namespace space
{
	//节点结构体
	template<class T>
	struct list_Node
	{
		list_Node<T>* prve;
		list_Node<T>* next;
		T _val;

		list_Node<T>(const T& val=T())//因为不确定_val类型是什么，所以不可以不给缺省值初始化，因为内置类型可以被初始化为0，自定义类型则不可以
			:prve(nullptr)
			,next(nullptr)
			,_val(val)
		{

		}
	};

	//封装迭代器，使得迭代器按照我们的需求实现

	template<class T>
	struct list_lterator
	{
		typedef list_Node<T> list_Node;
		list_Node* node;

		

	};

	template<class T>
	class list
	{
		typedef list_Node<T> Node;
	public:
		list<T>()
		{
			_head = new Node;
			_head->prve = _head;
			_head->next = _head;
		}
		void push_back(const T& val)
		{
			Node* newnode = new Node;
			Node* tail = _head->prve;

			tail->next = newnode;
			newnode->prve = tail;
			newnode->next = _head;
			_head->prve = newnode;
			newnode->_val = val;
		}

		
	private:
		Node* _head;
	};
}