#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <ostream>

using namespace std;

typedef pair<int, int> PAIR;
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
  return lhs.second < rhs.second;
}
struct CmpByValue {
  bool operator()(const PAIR& lhs, const PAIR& rhs) {
    return lhs.second < rhs.second;
  }
};


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
    
    int result;
    result = f(vector<int>(input), a,b,N);

    return 0;
}

int f(vector<int>(s),int a,int b,int N){
    int rs;
    int start = b+3;
    int tmp = start;
    vector<int>findn;
    map<int, int>findo;
    for (int c = 1; c <= N; c++){
        for (int i = 0; i < 3; i ++){
            for(int j =tmp-b-3;j<tmp-b;j++){
                if(j!=start && s[j] != 0){
                    findn.push_back(s[j]);
                    findo[j] = s[j];
                }
            }
            tmp += b+2;
        }
        start += (b+2)*(a+2);
        tmp = start;
    }
    for (int i = 0; i < 3*N; i ++){
        cout << findn[i];
    }
    cout << endl;
    for(int i = 0; i < (a+2)*(b+2)*N; i++){
        cout << findo[i];
    }
    
    map <int, int>::iterator itBegin = findo.begin ();
    for (; itBegin != findo.end (); ++itBegin){
        cout << "key=" << itBegin->first << ", value=" << itBegin->second << endl;
    }
        
    
    
    for(int i = 0; i < (a+2)*(b+2)*N; i++){
        for (int j = i+1; j < (a+2)*(b+2)*N; j ++){
            
        }
    }
    rs = 0;
    return rs;
}
int find(vector<int>){
    int funrs;
    
    
    return funrs;
}



