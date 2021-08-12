#include <iostream>
using namespace std;

int main(){
    
    int a, b[100];
    int cnt = 0;
    cin >> a;
    for (int i = 0; i < (2*a-2); i += 2){
        scanf("%d %d", &b[i], &b[i+1]);
    }
    for (int i = 1; i < (2*a-2); i += 2){
        for (int j = i; j < (2*a-2); j += 2){
            if (b[i] != b[j]){
                
            }
            else {
                cnt += 1;
            }
        }
    }
    if (cnt != 0){
        cout << "Error: " << cnt << "components" << endl;
        return 0;
    }
    else {
        
    }
    /*
     1 2
     1 3
     1 4
     2 5
     3 6
     4 7
     7 8
     */
    
    
    return 0;
}
