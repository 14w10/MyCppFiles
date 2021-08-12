#include <iostream>
using namespace std;

int max(int x, int y)
{
    int z;
    z = x > y ? x : y;
    return(z);
}

int main()
{
    int a, b, c;
    cout << "Input two integers: ";
    cin >> a >> b;
    c = max(a, b);
    cout << "Max = " << c << endl;
    return 0;
}
