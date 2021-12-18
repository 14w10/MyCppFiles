#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int* ini = new int[n];
    int* fin = new int[n];
    int* cha = new int[n];
    for (int i = 0; i < n; i ++) cin >> ini[i];
    for (int i = 0; i < n; i ++) cin >> fin[i];
    for (int i = 0; i < n; i ++){
        cha[i] = fin[i] - ini[i];
    }
    
    int gra = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (cha[i] * gra >= 0){
            ans += max(abs(cha[i]) - abs(gra), 0);
        }
        else{
            ans += abs(cha[i]);
        }
        gra = cha[i];
    }
    cout << ans << endl;

    return 0;
}
