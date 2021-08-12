#include <iostream>
using namespace std;
int main()
{
    int a, b;
    int c, d;
    cin >> a >> b;
    c = a + b;
    if (c < 0){
        d = -c;
    }
    else{
        d = c;
    }
    string e;
    e = d;
    int d_length;
    d_length = e.length();
    if (d_length == 7)
    {
        int siz_1 = (d - (d % 1000000))/1000000;
        int siz_3 = (d % 1000000) % 1000;
        int siz_2 = (d - siz_1 * 1000000 - siz_3)/1000;
        cout << siz_1 << "," << siz_2 << "," << siz_3 << '\n';
        return 0;
    }
    if (d_length < 7)
    {
        if (d_length < 4)
        {
            cout << d << '\n';
            return 0;
        }
        if (d_length >= 4)
        {
            int siz_12 = d % 1000;
            int siz_11 = (d - siz_12)/1000;
            cout << siz_11 << "," << siz_12 << '\n';
            return 0;
        }
    }
}
