#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
string rev(string);
int main(){
    int cnt;
    vector<char> chartostring;
    cin >> cnt;
    string strtmp;
    string str[cnt];
    string strc[cnt];
    for (int i = 0; i < cnt; i ++){
        cin >> str[i];
    }
    for (int i = 0; i < cnt; i ++){
        strc[i] = rev(str[i]);
    }
    bool t = false;
    int maji = 1;
    for(; maji < cnt; maji ++){
        string fi = strc[0];
        string tmm = strc[maji];
        char char1 = fi[0];
        char char2 = tmm[0];
        if(char1 == char2){
            t = true;
        }
        else{
            t = false;
        }
    }
    if (t == false){
        cout << "nai" << endl;
        return 0;
    }
    else {

        int rem = 1;
        for (int j = 1; j < str[0].length(); j ++){
            for(int i = 1; i < cnt; i ++){
                if(strc[0][j] == strc[i][j]){
                }
                else{
                    rem = j;
                    string ans = "";
                    for (int m = 0; m < rem; m ++){
                        ans += strc[0][m];
                    }
                    for (long i = ans.length()-1; i >= 0; i --){
                        cout << ans[i];
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }
}
string rev(string str){
    string tm = "";
    for (int i = 1; i <= str.length(); i ++){
        tm += str[str.length()-i];
    }
    tm += '\0';
    return tm;
}
