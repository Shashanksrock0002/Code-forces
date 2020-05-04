#include <iostream>
using namespace std;
string Water(int number)
{
    if (number < 0)
    {
        return "NO";
    }
    else
    {
        if (number == 2)
        {
            return "NO";
        }
        else if (number > 2 && number % 2 == 0)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
}
int main()
{
    int a;
    // cin >> a;
    // cout << Water(a);
    // cout << 5 / 2;
    int b = 100;
    double c = 1;
    for (int i = 0; i < 20; i++)
    {
        c = c * b;
        cout << i << ": " << c << endl;
    }
}