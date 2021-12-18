#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int ma[51][51];
int dp[51][51][5][2];

int main()
{
    int T; cin >> T;
    
    for(int t = 0; t < T; t ++){
        
        int N, K; cin >> N >> K;
        
        memset(dp, 0, sizeof(dp));
        
        dp[N][N - 1][0][1] = 1;
        dp[N - 1][N][0][0] = 1;
        
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= N; j ++) {
                char ch; cin >> ch;
                if (ch == 'H'){
                    ma[i][j] = 0;
                }
                else{
                    ma[i][j] = 1;
                }
            }
        }
        
        for (int i = 0; i <= K; i ++) {
            for (int j = N; j >= 1; j --) {
                for (int k = N; k >= 1; k --) {
                    if (ma[j][k] == 0) continue;
                    // change way
                    dp[j - 1][k][i + 1][0] += dp[j][k][i][1];
                    dp[j][k - 1][i + 1][1] += dp[j][k][i][0];
                    // not change way
                    dp[j - 1][k][i][0] += dp[j][k][i][0];
                    dp[j][k - 1][i][1] += dp[j][k][i][1];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= K; i ++) {
            ans += (dp[1][1][i][0] + dp[1][1][i][1]);
        }

        cout << ans << endl;
    }
    return 0;
}
