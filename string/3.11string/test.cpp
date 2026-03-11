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

//
//int main()
//{
//	string s("hello world");
//	cout << s.capacity() << endl;
//	//扩容：
//	s.resize(20);
//	cout << "capacity:" << s.capacity() << endl;
//	//删除数据：
//	s.resize(10);
//	cout << "capacity:" << s.capacity() << endl;
//	return 0;
//}


int main()
{
	string s("https://legacy.cplusplus.com/reference/string/string/");
	size_t pos1 = s.find(':', 0);//从第0位置开始找到':'字符所在位置
	string protocol;//协议
	if (pos1 != s.npos)
	{
		protocol = s.substr(0, pos1);//从零开始拷贝pos1长度(也就是https的长度)字符给protocol
	}
	cout << protocol << endl;
	size_t pos2 = s.find('/', (pos1 + 3));//从'l'位置开始找到/所在位置
	string domain;//域名
	if (pos2 != s.npos)
	{
		domain = s.substr((pos1 + 3), (pos2 - pos1 - 3));//拷贝域名
	}
	cout << domain << endl;
	string uri = s.substr(pos2 + 1);//拷贝资源，这里直接不给长度，默认是npos，就直接将后面的字符全部拷贝了
	cout << uri << endl;
	return 0;
}