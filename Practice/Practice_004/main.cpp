#include <iostream>
using namespace std;
int main()
{
    int max_4(int, int, int, int);
    int a, b, c, d, result;
    cout << "Input four numbers you are going to compare:" << endl;
    cin >> a >> b >> c >> d;
    result = max_4(a, b, c, d);
    cout << "The biggest number is: " << result << endl;
    return 0;
}
int max_4(int a, int b, int c, int d)
{
    int max(int, int);
    int n;
    n = max(a, b);
    n = max(n, c);
    n = max(n, d);
    return n;
}
int max(int x, int y)
{
    if (x > y) return x;
    else return y;
}
