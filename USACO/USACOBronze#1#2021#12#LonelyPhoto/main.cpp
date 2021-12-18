#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define LL long long

using namespace std;

int main() {

    int n; cin >> n;
    string str; cin >> str;
    int lg, lh, cg, ch;
    lg = lh = cg = ch = -1;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'G') {
            lg = cg; cg = i;
        }
        else {
            lh = ch; ch = i;
        }
        int l = min(lg, lh) + 1;
        LL tmp = (LL)(i - l) + 1;
        if (tmp < 3) continue;
        ans += (tmp - 2);
    }
    
    int rh = str[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (str[i] == rh) {
            cnt++;
        }
        else {
            if (cnt >= 3) {
                LL tmp = (LL)(cnt - 1) * (LL)(cnt - 2);
                tmp /= 2;
                ans = ans - tmp;
            }
            rh = str[i];
            cnt = 1;
        }
    }
    if (cnt >= 3) {
        LL tmp = (LL)(cnt - 1) * (LL)(cnt - 2);
        tmp /= 2;
        ans = ans - tmp;
    }
    cout << ans << endl;

    return 0;
}
