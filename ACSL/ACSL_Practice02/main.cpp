#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main(){
    int cntOfPath;
    cin >> cntOfPath;
    
    int arr[82];
    int cnt = 0;
    int a,index = 0;
    while(cin >> a){
        arr[index++] = a;
        char ch = getchar();
        cnt += 1;
        if(ch == '\n')
            break;
    }
    int tmp1[cnt];
    for (int i = 0; i < cnt; i ++){
        tmp1[i] = arr[i];
    }

    int matrix1[9][9] = {0};
    int matrix2[9][9] = {0};
    int matrixtmp[9][9] = {0};
    for (int i = 0; i < cnt; i++){
        int tmpint = tmp1[i];
        int start = tmpint / 10;
        int end = tmpint % 10;
        matrix1[start-1][end-1] += 1;
        matrix2[start-1][end-1] += 1;
        matrixtmp[start-1][end-1] += 1;
    }
    int ccnt = 0;
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if(matrixtmp[i][j] == 1){
                ccnt += 1;
            }
        }
    }
    while(cntOfPath != 0){
        for(int i = 0 ; i < 9; i ++){
            for(int j = 0 ;j<9; j++){
                for (int m = 0; m < 9; m++){
                    matrixtmp[i][j] += matrix1[i][m]*matrix2[m][j];
                }
            }
        }
        for(int i = 0 ; i < 9; i ++){
            for(int j = 0 ;j<9; j++){
                matrix2[i][j] = matrixtmp[i][j];
            }
        }
        for(int i = 0 ; i < 9; i ++){
            for(int j = 0 ;j<9; j++){
                ccnt += matrixtmp[i][j];
            }
        }
        cntOfPath -= 1;
        
    }
    cout << ccnt << endl;
    return 0;
}

