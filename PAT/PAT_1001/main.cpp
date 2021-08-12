#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int sum;
    sum = a + b;
    if (sum == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    bool negative = false;
    if (sum < 0)
    {
        negative = true;
        sum = -sum;
    }
    char str[15];
    int cnt = 0, comma = 0;
    while (sum)
    {
        str[cnt++] = sum % 10 + '0';
        comma ++;
        if (comma % 3 == 0 && sum >= 10)
        {
            str[cnt++] = ',';
            comma = 0;
        }
        sum /= 10;
    }
    if (negative) putchar('-');
    for (int i = cnt - 1; i >= 0; -- i)
    {
        putchar(str[i]);
    }
    cout << '\n';
    return 0;
}
