#include <iostream>
#include <string>
#include <vector>

using namespace std;
void f(string,string,long,long);
string ff(string,string,long,long);
string fff(string,long);
void ffff(string, string, string, string);


int main(){
    string a,b,c,d;
    cin >> a >> b;
    long as = a.length();
    long bs = b.length();
    f(a,b,as,bs);
    return 0;
}

void f(string s1, string s2, long s1length, long s2length){
    string ss1, ss2, ss3, ss4;
    ss1 = ff(s1, s2, s1length, s2length);
    ss2 = ff(s2, s1, s2length, s1length);
    s1 = fff(s1, s1length);
    s2 = fff(s2, s2length);
    ss3 = ff(s1, s2, s1length, s2length);
    ss4 = ff(s2, s1, s2length, s1length);
    string result;
    ffff(ss1, ss2, ss3, ss4);
}

string ff(string s1, string s2, long s1length, long s2length){ // s1=abcddef;s2=vdfaddwf;s3=feddcba;s4=vdfaddwf;
    vector<char>rst;
    
    const char* str1 = s1.data();
    const char* str2 = s2.data();
    
    int nxnum = 0;
    for (int i = 0; i < s1length; i ++){
        for (int j = nxnum; j < s2length; j ++){
            if (str1[i] == str2[j]) {
                nxnum = j + 1;
                rst.push_back(str1[i]);
                break;
            }
        }
        if (nxnum == s2length) break;
    }
    string str_tmp;
    str_tmp.assign(rst.begin(),rst.end());
    return str_tmp;
}

string fff(string s1,long s1length){
    
    const char* str1 = s1.data();
    vector<char> str1_tmp;
    
    for (long i = s1length-1; i >= 0; i --){
        str1_tmp.push_back(str1[i]);
    }
    s1.assign(str1_tmp.begin(),str1_tmp.end());
    return s1;
}

void ffff(string ss1, string ss2, string ss3, string ss4){
    /*
     *ss1=dnbfdg
     *ss2=ng
     *ss3=gfds
     *ss4=dghs
     */
    long s1,s2,s3,s4;
    s1 = ss1.length(); s2 = ss2.length(); s3 = ss3.length(); s4 = ss4.length();
    for (int i = 0; i < s1; i++){
        for(int j; j < )
    }
    
    
}
