#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <numeric>

using namespace std;

string f(int);
int main(){
    int a, b, c;
    string ar, br, cr;
    cin >> a >> b >> c;
    ar = f(a);
    br = f(b);
    cr = f(c);
    cout << "#" << ar << br << cr << endl;
    return 0;
}
string f(int x){
    int tmp1 = x;
    int tmp2 = x;
    int cnt = 1;
    string str;
    vector<string> sr;
    vector<string> srtmp;
    while(tmp1/13 != 0){
        cnt += 1;
        tmp1/=13;
    }
    for (int i = 0; i < cnt; i++){
        tmp2 = x%13;
        if(tmp2<10){
            string tmpc;
            stringstream ss;
            ss << tmp2;
            tmpc = ss.str();
            sr.push_back(tmpc);
        }
        else{
             switch(tmp2){
                 case 10: sr.push_back("A");
                 case 11: sr.push_back("B");
                 case 12: sr.push_back("C");
             }
        }
        x/=13;
    }
    if(cnt == 1){
        int ttmp = 0;
        string tttmpc;
        stringstream sstttmp;
        sstttmp << ttmp;
        tttmpc = sstttmp.str();
        srtmp.push_back(tttmpc);
    }
    for (int i = cnt; i > 0; i --){
        srtmp.push_back(sr[i-1]);
    }
    str = accumulate(srtmp.begin(), srtmp.end(), str);
    return str;
}
