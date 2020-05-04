#include <iostream>
using namespace std;
long long int number(long long int a, long long int b, long long int c)
{
    long long int d, e;
    d = a / c;
    e = b / c;
    if (c > a && c > b)
    {
        return 1;
    }
    if (a == b && b == c)
    {
        return 1;
    }
    if (a >= c || b >= c)
    {
        if (a % c != 0)
            d++;
        if (b % c != 0)
            e++;
    }
    // string s = to_string(d * e);
    return d * e;
}

int main()
{
    long long int a, b;
    long long int c;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << number(a, b, c);
    // // cout << 1e40;
    // cout << number(1e19, 1e19, 1);
    // cout << 1e19 * 1e19;
    return 0;
}