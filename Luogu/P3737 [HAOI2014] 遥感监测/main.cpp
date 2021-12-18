#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define eps 1e-10

using namespace std;

int r, n, ans;

struct Node{
    int x,y;double l,r;
}node[110];
inline bool cmp(struct Node x,struct Node y){
    return x.r < y.r;
}

int main()
{
    cin >> n >> r;
    for(int i=1;i<=n;i++)
    {
        cin >> node[i].x >> node[i].y;
        node[i].l = (double)node[i].x - sqrt(((double)r * r) - node[i].y * node[i].y);
        node[i].r = (double)node[i].x + sqrt(((double)r * r) - node[i].y * node[i].y);
    }
    sort(&node[1], &node[1 + n], cmp);
    double rr = node[1].r;
    for(int i = 2; i <= n; i ++){
        if(node[i].l - eps>rr) ans ++ ,rr = node[i].r;
    }
    cout << ans + 1 << endl;
    return 0;
}
