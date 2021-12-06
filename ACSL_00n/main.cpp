#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
//    string str;
//    cin >> str;
//    const char* s1 = str.data();
//    int cnt;
//    cnt = (int)s1[0];
//    cout << cnt << endl;
//    vector<char> a;
//    for (int i = 0; i < cnt; i ++){
//        a.push_back(s1[i]);
//    }
//    vector<char> back;
//    for (long i = str.length()-1; i >= cnt; i --){
//        back.push_back(s1[i]);
//    }
//    string aa;
//    aa.assign(a.begin(),a.end());
//    string bb;
//    bb.assign(back.begin(),back.end());
//    cout << aa << " " << bb << endl;
    string str;
    cin >> str;
    int fs;
    fs = stoi(str);
    long slen = str.length();
    for (int i = 0; i < slen - 1; i ++){
        fs /= 10;
    }
    reverse(str.begin(), str.end());
    int ia = stoi(str);
    for (int i = 0; i < fs+1; i ++){
        ia /= 10;
    }
    int fa = ia;
    slen = slen - fs - 1;
    vector<char>a;
    for (int i = 0; i < slen; i ++){
        a.push_back(fa%10);
        fa/=10;
    }
    vector<char>::iterator ite = a.begin();
    for (; ite != a.end(); ite++){
            cout << *ite;
    }
    cout << endl;
    cout << slen << endl;
    string sss;
    sss.assign(a.begin(),a.end());
    cout << sss << endl;
    return 0;
}
