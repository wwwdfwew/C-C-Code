#include <iostream>
using namespace std;

long long factorial(int n);

int main() {

    int n;
    cin >> n;

    cout << factorial(n) << endl;

    return 0;
}

long long factorial(int n) {

    long long sum = 1;
    if (n > 1)
    {
        sum = n * factorial(n - 1);
        return sum;
    }
    else
        return n;

}