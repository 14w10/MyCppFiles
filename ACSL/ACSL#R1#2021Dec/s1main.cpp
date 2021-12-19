#include <iostream>
#include <cstring>

using namespace std;

int H = 0, M = 0, S = 0;
char ret;
string re;
int c;
int cnt[6];

string exc(char c, char* str){
    switch (c) {
        case 'G':
            re = 'm';
            break;
        case 'R':
            re = 'h';
            break;
        case 'B':
            re = 's';
            break;
        case 'Y':
            re = "hm";
            break;
        case 'M':
            re = "hs";
            break;
        case 'C':
            re = "ms";
            break;
        case 'W':
            re = 'w';
            break;
    }
    return re;
}

int cir(int c){
    switch (c) {
        case 0:
            c = 1;
            break;
        case 1:
            c = 1;
            break;
        case 2:
            c = 2;
            break;
        case 3:
            c = 3;
            break;
        case 4:
            c = 5;
            break;
    }
    return c;
}


int main(){
    string str;
    cin >> str;
    char cstr[str.length()];
    strcpy(cstr, str.c_str());
    for(int i = 0; i < 5; i ++){
        if(exc(cstr[i], cstr) == "h"){
            H += cir(i);
        }
        else if(exc(cstr[i], cstr) == "m"){
            M += cir(i)*5;
        }
        else if(exc(cstr[i], cstr) == "s"){
            S += cir(i)*5;
        }
        else if(exc(cstr[i], cstr) == "hm"){
            H += cir(i);
            M += cir(i)*5;
        }
        else if(exc(cstr[i], cstr) == "hs"){
            H += cir(i);
            S += cir(i)*5;
        }
        else if(exc(cstr[i], cstr) == "ms"){
            M += cir(i)*5;
            S += cir(i)*5;
        }
    }
    string hh, mm, ss;
    if(S >= 60){
        M += (S/60);
        S -= (S/60)*60;
    }
    if(M >= 60){
        H += (M/60);
        M -= (M/60)*60;
    }
    if(H < 10){
        hh = '0' + to_string(H);
    }
    else{
        hh = to_string(H);
    }
    if(M < 10){
        mm = '0'+ to_string(M);
    }
    else{
        mm = to_string(M);
    }
    if(S < 10){
        ss = '0'+ to_string(S);
    }
    else{
        ss = to_string(S);
    }
    cout << hh << ":" << mm << ":" << ss << endl;
    return 0;
    
}
