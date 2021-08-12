#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Put in the Fahrenheit temperature:\n";
    cin >> a;
    int b, c;
    b = (a-32)* 5;
    c = b/9;
    cout << "Celsius temperature: \n" << c << endl;
    return 0;
}
