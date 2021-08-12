#include <iostream>
using namespace std;

int seqCnt, para;
int sort(int);
int main(){
    cin >> seqCnt >> para;
    int seqArr[seqCnt];
    for (int i = 0; i < seqCnt; i++){
        cin >> seqArr[i];
    }
    int seqArrChanged[seqCnt];
    seqArrChanged = sort(seqArr[seqCnt]);
    
    return 0;
}

int sort(int arr[seqCnt]){
    
}
