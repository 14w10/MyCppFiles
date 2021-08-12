#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <ostream>

using namespace std;


int f(vector<int>,int,int,int);
int find(vector<int>);
int main(){
    int a, b, N;
    cin >> a >> b >> N;
    vector<int>input;
    for (int i = 0; i < N; i ++){
        for (int m = 0; m < b+3; m ++){
            input.push_back(0);
        }
        for (int j = 0; j < a; j ++){
            for (int jj = 0; jj < b; jj ++){
                int t;
                cin >> t;
                input.push_back(t);
                }
            for (int n = 0; n < 2; n++){
                input.push_back(0);
            }
        }
        for (int m = 0; m < b+1; m ++){
            input.push_back(0);
        }
    }
    for (int cnt = 0; cnt < (a+2)*(b+2)*N; cnt ++){
        cout << input[cnt];
    }
    cout << endl;
    
    int result = 0;
    result += f(vector<int>(input), a,b,N);

    return 0;
}

int f(vector<int>(s),int a,int b,int N){
    int rs;
    int start = b+3;
    int tmp = start;
    map<int, int>findo;
    for (int c = 1; c <= N; c++){
        for (int i = 0; i < 3; i ++){
            for(int j =tmp-b-3;j<tmp-b;j++){
                if(j!=start && s[j] != 0){
                    findo[j] = s[j];
                }
            }
            tmp += b+2;
        }
        start += (b+2)*(a+2);
        tmp = start;
    }
    cout << endl;
    for(int i = 0; i < (a+2)*(b+2)*N; i++){
        cout << findo[i];
    }
    for(int i = 0 ; i < (a+2)*(b+2)*N; i ++){
        for (int j = i+1; j < (a+2)*(b+2)*N; j ++){
            while(findo[i]==findo[j]&&findo[i]!=0&&findo[j]!=0){
                for (int m = j+1; m < (a+2)*(b+2)*N; m ++){
                    if(findo[j] == findo[m]){
                        findo[i] = 0;
                    }
                }
            }
        }
    }
    

    rs = 0;
    return rs;
}
