#include <iostream>
#include <bitset>
#include <iomanip>
#define int long long

using namespace std;
int s, d, r;

int f(int , int , int);
int result[5];
signed main() {
    for (int i = 0; i < 5; i ++){
        cin >> hex >> s >> hex >> d >> dec >> r;
        result[i] = f(s, d, r);
    }
    for (int j = 0; j < 5; j++){
        cout << j+1 << ". " << setiosflags(ios::uppercase) << hex << result[j] << endl;
    }
    return 0;
}
int f(int s, int d, int r){
    int ten = 0x10;
    int res_sum;
    res_sum = (r*r*r*d-r*d+2*s*r)/2;
    int sum;
    do {
        sum = 0x0;
        do{
            sum += res_sum%ten;
            res_sum /= ten;
        } while (res_sum / ten > 0);
        sum += res_sum;
        res_sum = sum;
    } while (res_sum / ten > 0);
    return sum;
}
