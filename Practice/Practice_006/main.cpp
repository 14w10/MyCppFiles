#include <iostream>
using namespace std;
int main()
{
    long factory(int);
    int x;
    cout << "INPUT: " << endl;
    cin >> x;
    long result;
    result = factory(x);
    cout << "RESULT(n!): " << result << endl;
    return 0;
}
long factory(int n)
{
    long f;
    if (n < 0)
    {
        cout << "DATA ERROR!!" << endl;
        f = -1;
    }
    else if (n == 0 || n == 1) f = 1;
    else f = factory(n - 1) * n;
    return f;
}
