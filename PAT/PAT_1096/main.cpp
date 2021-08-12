#include <iostream>
#include <cmath>
using namespace std;
int ques;

int main(){
    int fun1(int);
    string fun2(int);
    cin >> ques;
    cout << fun1(ques) << endl;
    cout << fun2(ques) << endl;
    return 0;
}

int fun1(int a){
    int root;
    root = sqrt(a);
    for (int i = root-1; i > 2; i --){
        if (a % i == 0){
            
        }
    }
}

string fun2(int b){
    
}
