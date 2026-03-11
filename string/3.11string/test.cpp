#include<iostream>
#include<string>
using namespace std;

////一般情况下string自动扩容
//int main()
//{
//	string s("hello world");
//	cout << s.capacity() << endl;
//	size_t oldcapacity = s.capacity();
//	for (size_t i = 0; i < 100; i++)
//	{
//		s.push_back('x');
//		if (oldcapacity != s.capacity())
//		{
//			oldcapacity = s.capacity();
//		}
//	}
//	cout << "扩容后：" << s.capacity() << endl;
//	return 0;
//}
//
//
////我们提前扩容100个空间
//int main()
//{
//	string s("hello world");
//	s.reserve(100);//扩容100个空间
//	cout << s.capacity() << endl;
//	size_t oldcapacity = s.capacity();
//	for (size_t i = 0; i < 100; i++)
//	{
//		s.push_back('x');
//		if (oldcapacity != s.capacity())
//		{
//			oldcapacity = s.capacity();
//		}
//	}
//	cout << "扩容后：" << s.capacity() << endl;
//	return 0;
//}

//
//int main()
//{
//	string s("hello world");
//	s.reserve(100);//扩容100个空间
//	cout << s.capacity() << endl;
//	size_t oldcapacity = s.capacity();
//	for (size_t i = 0; i < 100; i++)
//	{
//		s.push_back('x');
//		if (oldcapacity != s.capacity())
//		{
//			oldcapacity = s.capacity();
//		}
//	}
//	cout << "扩容后：" << s.capacity() << endl;
//
//	s.clear();
//	s.reserve(50);
//	cout << "缩容后：" << s.capacity() << endl;
//
//	
//	return 0;
//}


int main()
{
	string s("hello world");
	cout << s.capacity() << endl;
	//扩容：
	s.resize(20);
	cout << "capacity:" << s.capacity() << endl;
	//删除数据：
	s.resize(10);
	cout << "capacity:" << s.capacity() << endl;
	return 0;
}