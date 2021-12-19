#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int* a = new int[100010];
vector<int> postag[100010];
int* use = new int[100010];
int n, m;

int trans(int x){
    if(a[x] == x){
        return x;
    }
    else{
        a[x] = trans(a[x]);
        return a[x];
    }
}

LL calpri(int fin, int x) {
    
    long ai = upper_bound(postag[x].begin(), postag[x].end(), fin) - postag[x].begin();
    LL dis = 0;
    if (ai == postag[x].size()) {
        int l = postag[x][ai - 1];
        dis = (LL)(fin - l) * (LL)(fin - l);
    }
    else if (ai == 0) {
        int r = postag[x][ai];
        dis = (LL)(r - fin) * (LL)(r - fin);
    }
    else {
        int r = postag[x][ai];
        int l = postag[x][ai - 1];
        dis = (LL)min(r - fin, fin - l);
        dis = dis * dis;
    }
    return dis;
}

LL check(int start, int end) {
    
    LL inf = (LL)(n + 10) * (LL)(n + 10) * 10;
    LL ans = inf;

    for (int i = 0; i < n; i ++) use[i+1] = 0;
    for (int i = 0; i < n; i ++) {
        if (use[i+1]) continue;
        if (a[i+1] == start) {
            ans = min(ans, calpri(i+1, end));
            use[i+1] = 1;
        }
        else if (a[i+1] == end) {
            use[i+1] = 1;
        }
        else {
            int x = a[i+1];
            LL miStart = inf;
            LL miEnd = inf;
            for (int j = 0; j < postag[x].size(); j ++) {
                int pos = postag[x][j];
                use[pos] = 1;
                miStart = min(miStart, calpri(pos, start));
                miEnd = min(miEnd, calpri(pos, end));
            }
            ans = min(ans, miStart + miEnd);
        }
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i ++){
        cin >> n >> m;
        for(int i = 0; i < n; i ++){
            a[i+1] = i+1;
            use[i+1] = 0;
        }
        int x, y;
        for(int i = 0; i < m; i ++){
            cin >> x >> y;
            int fx = trans(x);
            int fy = trans(y);
            if (fx != fy){
                a[fx] = fy;
            }
        }
        for(int i = 0; i < n; i ++){
            postag[i+1].clear();
        }
        for(int i = 0; i < n; i++){
            a[i+1] = trans(i+1);
            postag[a[i+1]].push_back(i+1);
        }

        LL ans;
        if(a[1] == a[n]){
            ans = 0;
        }
        else{
            ans = check(a[1], a[n]);
        }
        cout << ans << endl;
    }

    return 0;
}
