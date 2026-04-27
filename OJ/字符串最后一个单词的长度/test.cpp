#include <iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    size_t pos = s.rfind(' ');
    if (pos != s.npos)
    {
        cout << s.size() - pos - 1;
    }
    else
    {
        cout << s.size();
    }
    return 0;
}