#include <iostream>
using namespace std;

int main() {
    long long a[5001], b[5001];
    long long sum1[10001], sum2[10001];
    int left, right;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= 2 * m; i ++){
        sum1[i] = sum2[i] = 0;
    }
    
    for(int i = 1; i <= m; i ++){
        a[i] = b[i] = 0;
    }
    
    for(int i = 1; i <= n; i ++){
        cin >> left >> right;
        a[left] ++;
        b[right] ++;
    }

    for(int i = 0; i <= m; i ++){
        for (int j = 0; j <= m; j ++) {
            sum1[i + j] += (a[i] * a[j]);
            sum2[i + j] += (b[i] * b[j]);
        }
    }

    long long total = sum1[0];
    cout << total << endl;
    for(int k = 1; k <= 2 * m; k ++){
        total += sum1[k];
        total -= sum2[k - 1];
        cout << total << endl;
    }
}
