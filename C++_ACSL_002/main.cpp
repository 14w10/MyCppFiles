#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <ctype.h>
#include <sstream>
#include <map>

using namespace std;


int main(){
    string line;
    vector<char> ss;
    getline(cin,line);
    long llen = line.length();
    const char* s1 = line.data();
    for (int i = 0; i < llen; i ++){
        if (s1[i] == ' ' || s1[i] == ',' || s1[i] == '.' || s1[i] == '?' || s1[i] == '!'){
        }
        else{
            ss.push_back(s1[i]);
        }
    }
    stringstream ssrst;
    string str;
    copy(ss.begin(),ss.end(),ostream_iterator<char>(ssrst,""));
    str=ssrst.str();
    llen = str.length();
    for (int i = 0; i < llen; i ++){
        for (int j = i+1; j < llen; j ++){
            if (str[i] > str[j]){
                char tmp;
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
    int cnt = 0;
    int ctm = 0;
    while(ctm <= llen){
        if(str[ctm] == str[ctm+1]){
            ctm += 1;
        }
        else{
            ctm += 1;
            cnt += 1;
        }
    }
    vector<char> rstv;
    map<char, int> fir;
    fir[str[0]] = 1;
    for (int i = 1; i < llen; i ++){
        
        if(str[i] != str[i-1]){
            fir[str[i]] = 1;
        }
        else{
            fir[str[i]] += 1;
        }
    }
    map<int, string> sec;
    int tt = 0;
    sec[fir[str[0]]] = str[0];
    while(tt < llen){
        
        if(str[tt] != str[tt+1]){
            if(fir[str[tt]] == fir[str[tt+1]]){
                sec[fir[str[tt]]] += str[tt+1];
            }
            else{
                sec[fir[str[tt+1]]] += str[tt+1];
            }
            tt += 1;
        }
        else{
            tt += 1;
        }
    }
    int tmp = int(sec.size()-1);
    for ( ; tmp > 0; --tmp){
        cout << tmp << sec[tmp];
        if (tmp != 1){
            cout << ",";
        }
    }
    cout << endl;
    
    
    return 0;
}




