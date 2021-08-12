#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int i;
    int sum;
    sum = 0;
    for (i = 0; i < a.length(); i ++)
    {
        sum += a[i] - 48;
    }
    string num = to_string(sum);
    int j;
    int num_group[num.length() - 1];
    for (j = 0; j < num.length(); j ++)
    {
        num_group[j] = num[j];
    }
    int m;
    for (m = 0; m < num.length(); m ++)
    {
        switch(num_group[m] - 48)
        {
            case 0:
                cout << "zero";
                break;
            case 1:
                cout << "one";
                break;
            case 2:
                cout << "two";
                break;
            case 3:
                cout << "three";
                break;
            case 4:
                cout << "four";
                break;
            case 5:
                cout << "five";
                break;
            case 6:
                cout << "six";
                break;
            case 7:
                cout << "seven";
                break;
            case 8:
                cout << "eight";
                break;
            case 9:
                cout << "nine";
                break;
        }
        if (m != num.length() - 1)
        {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
