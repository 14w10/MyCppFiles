#include <iostream>
#include <bitset>
#include <sstream>
// #include <bits/stdc++.h>
using namespace std;

int f(int , int , int);
int s, d, r, ten, m, cnt = 0;
int result[5];
int main() {
    cin >> hex >> s;
    ten = 0x10;
    d = s/ten;
    r = s%ten;
    
    for (int m = 1; m <= 6; m ++){
        if (s / ten > 0){
            cout << "yes" << endl;
        }
    }

}


