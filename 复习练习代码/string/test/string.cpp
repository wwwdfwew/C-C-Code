#include<string>
#include<vector>
#include<list>
#include <algorithm>
#include<iostream>

using namespace std;

void Pget(const string& s)
{
	string::const_iterator st = s.begin();
	while (st != s.end())
	{
		cout << *st << " ";
		st++;
	}
}
int main()
{
	/*string：是一个管理字符串的类，其实就是一个存储字符的顺序表
////1.重载operator[]:用于自定义类型对象通过下标访问数据*/
	string s("hello world");
	cout << s[2] << endl;
//////2.重载operator[]可以修改值，因为它返回的是访问元素的引用。它的用法和数组相似。
	s[2] = 'o';
	cout << s << endl;
///////3.要区分数组的[]加下标的原理和自定义类型对象的[]加下标的原理

	char s1[] = { "hello world" };
	string s2 = "hello world";
	s1[1];/*——》解引用：*(s1+1)*/
	s2[1];/*——》对象进行函数调用：s2.operator[](1)*/



///////////////////////////////////////string类对象如何进行遍历
	//1.使用for循环
	string s3("hello world");
		for (size_t i = 0; i < s3.size(); i++)
		{
			cout << s3[i] << " ";
			s3[i]++;//也可以进行修改
		}
		cout << endl;
	//2.使用范围for:
		string s4("hello world");
		for (auto e : s4)
		{
			cout << e <<" ";
		}
		cout << endl;
		//要想修改数据，加引用，因为范围for是将s4的值取出赋给e，是拷贝
		for (auto& e : s4)
		{
			cout << e <<" ";
			e++;
		}
		cout << endl;
	//3.迭代器：迭代器是一个像指针的数据类型，可以是指针，但也不一定是指针，它的关键词是iterator
		//因为迭代器是在类里面进行声明定义的，所以要使用迭代器，就需要加域访问限定符"::"
		string s5("hello world");
		string::iterator it = s5.begin();
		while (it != s5.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		//begin()指向的是第一个元素，end()指向的是最后一个元素的下一个位置
		///1.作用或者意义：
		//1)范围for的底层是迭代器，当编译器在编译时，直接将范围for替换成迭代器，像上面范围for的例子，
		//其实就是将*it赋给e*
		//2)迭代器是通用的，它适用于所有的容器，除了无法进行遍历的容器
	///总结：iterator的作用就是提供统一的方式来访问或者修改容器的数据
		//统一的方式：可以看到，我们容器涉及到迭代器访问和修改数据，他们的逻辑都差不多，很类似
		vector<int> vct;
		vct.push_back(1);
		vct.push_back(2);
		vct.push_back(3);
		vct.push_back(4);
		vector<int>::iterator vt = vct.begin();
		while (vt != vct.end())
		{
			cout << *vt << " ";
			vt++;
		}
		cout << endl;
		//2.迭代器可以和其他容器进行配合，比如说算法
		/*我们使用算法来修改数据时，由于一些类的数据被封装成私有的了，因此不能直接访问，那么就可以通过迭代器来进行数据的
		访问和修改*/
		//比如说逆置算法：
		reverse(vct.begin(), vct.end());
	/*	for (auto e : vct)
		{
			cout << e << " ";
		}*/
		vector<int>::iterator v = vct.begin();
		while (v != vct.end())
		{
			cout << *v << " ";
			v++;
		}
		cout << endl;
		//3,反向迭代器，补充一下，我们范围for底层实现的迭代器是正向迭代器。
		//关键词：reverse_iterator

		string s6("hello world");
		string::reverse_iterator st6 = s6.rbegin();
		while (st6!= s6.rend())
		{
			cout << *st6 << " ";
			st6++;
		}
		cout << endl;
		//这里要使用rbegin和rend
		//4.const迭代器，如果遇到一些不能够修改的数据，我们就需要用const修饰的迭代器
		/*void Pget(const string & s)
		{
			string::const_iterator st = s.begin();
			while (st != s.end())
			{
				cout << *st << " ";
				st++;
			}
		}*/
		Pget("hello world");

		//string中的方法：

		//size():计算数组中数据的个数，不包括/0
		//length():和size的功能一样
		//capacity()计算数组的大小，容量，不一定等于size()。
		//扩容，编译环境不同，扩容规则也可能不同
		string s7("hello world");
		cout << s7.size() << endl;
		cout << s7.length() << endl;
		cout << s7.capacity() << endl;
		//扩容：
		size_t old = s7.capacity();
		for (int i = 0; i <= 100; i++)
		{
			s7 += 'x';
			if (old != s7.capacity())
			{
				cout << "s7.capacity():" << old << endl;
				old = s7.capacity();
			}
		}
		//在Linux环境下，相同的代码，扩容的规律不同。
//----------------------------------reserve():也是扩容，用于提前开空间，适合那些知道需要多少空间的情况
		string s8("hello world");
		s8.reserve(100);
		cout << s8.size() << endl;
		cout << s8.capacity() << endl;
		//缩容:当我们的字符串数组中没有数据，且开的空间小于capacity时，就会缩容,但这是不稳定的，在不同环境下结果可能不一样
		s8.clear();
		s8.reserve(20);
		cout << s8.size() << endl;
		cout << s8.capacity() << endl;
		cout << endl;
//------------------------resize():也是扩容，但是可以初始化，因为初始化填有数据，因此size也会改变,若不给定初始化的值，则默认为0
		string s9("hello world");
		s9.resize(100);
		cout << s9.size() << endl;
		cout << s9.capacity() << endl;
		//当n<length时，就会删除数据，但是不缩容
		s9.resize(20);
		cout << s9.size() << endl;
		cout << s9.capacity() << endl;
		cout << endl;
////--------------------------at：功能和[]一样，不同的是对错误的处理，[]是断言，at是抛出异常
		string s10 = "hello world";
		//s10[20];//直接中止程序
		//s10.at(20);//抛出异常

		//捕获异常：
		/*try {
			s10.at(30);
		}
		catch(const exception& e)
		{
			cout << e.what() << endl;
		}*/

////--------------------------insert：在任意位置插入字符或者插入n个字符
		string s11 = "hello world";
		s11.insert(5, "code");
		s11.insert(0, 1,'x');//在第一个位置插入一个字符
		cout << s11 << endl;
///---------------------------erase:从pos位置开始删除n个字符
		s11.erase(0,1);//头删
		s11.erase(5, 4);//从第五个位置删除四个字符
		cout << s11 << endl;
//////insert和erase都需要提供位置和多个个字符，除了用迭代器时。


//////------------------------replace:从pos位置开始替换n个字符，其实是将一个区间内的数据替换成指定的字符串

		s11.replace(0, 5, "world");
		cout << s11<<endl;

/////--------------------------c_str:返回string 对象中的char *类型变量
	
		cout << s11.c_str() << endl;//因为C++是兼容C的，因此有些场景C可以做，C++不能做，就需要用到这些方法
		cout << endl;
////---------------------------find:查找字符，找到则返回对应元素下标,未找到则返回-1
		int num = s11.find("l");
		cout << num << endl;
////---------------------------rfind:从后往前找，找到则返回对应元素下标,未找到则返回-1
		int num1 = s11.rfind('l');
		cout << num1 << endl;
///---------------------------operator +:字符串相加，但是不改变对象本身
///---------------------------operator+=:改变自身
///---------------------------getline:从标准输入里面获取字符串存储到指定对象，可指定分割符，默认为换行符
		/*string get;
		getline(cin, get);
		cout << get << endl;*/
////作用是什么呢，因为用cin>>get接收字符串，空格和分隔符也会作为分隔符，因此要是输入带有空格的字符串，在一些场景的使用中
////会出现问题。

////---------------------------substr:从pos位置开始取n个字符
		string s12 = "hello world";
		string s13 = s12.substr(0, 5);
		cout << endl << s13 << endl;

	return 0;
}