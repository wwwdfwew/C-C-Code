#include <iostream>
#include<string>
using namespace std;

//int main()
//{
//    string s;
//    cin >> s;
//    size_t pos = s.rfind(' ');
//    if (pos != s.npos)
//    {
//        cout << s.size() - pos - 1;
//    }
//    else
//    {
//        cout << s.size();
//    }
//    return 0;
//}


//int main()
//{
//    std::string str("Please, replace the vowels in this sentence by asterisks.");
//    std::size_t found = str.find_first_of("aeiou");
//    while (found != std::string::npos)
//    {
//        str[found] = '*';
//        found = str.find_first_of("aeiou", found + 1);
//    }
//
//    std::cout << str << '\n';
//    return 0;
//}

int main()
{
	string s("hello world");
	s.erase(6, 5);//删除world： string& erase (size_t pos = 0, size_t len = npos);
	cout << s << endl;
	s.erase(s.begin() + 2);//删除第一个'l'：iterator erase (iterator p);
	cout << s << endl;
	s.erase(s.begin(), s.end() - 5);//删除区间：iterator erase (iterator first, iterator last);
	cout << s << endl;
	return 0;
}