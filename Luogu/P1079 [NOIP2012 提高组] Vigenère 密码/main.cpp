#include <iostream>
#include <cstring>
using namespace std;

bool f(char c){
    if(c > 96){
        return false;
    }
    else return true;
}
int main (){
    string k;
    string s;
    cin >> k; cin >> s;
    unsigned long slen = s.length();
    unsigned long klen = k.length();
    char schar[slen]; char kchar[klen];
    char nchar[slen]; char kchartmp[klen];
    strcpy(schar, s.c_str()); strcpy(kchar, k.c_str());
    for(int i = 0; i < slen; i ++){
        strcpy(kchartmp, k.c_str());
        bool sj = f(schar[i]);
        bool kj = f(kchar[i%klen]);
        if(kj){
            kchartmp[i%klen] += 32;
        }
        if(sj){
            schar[i] += 32;
        }
        int dif = (schar[i] - kchartmp[i%klen] + 26) % 26;
        nchar[i] = dif + 65 + 32;
        if(sj){
            nchar[i] -= 32;
        }
    }
    for(int i = 0; i < slen; i ++){
        cout << nchar[i];
    }
    cout << endl;
    return 0;
}
