#include <iostream>
using namespace std;

struct
{
    char name[20];
    int etime;
    int ltime;
} per[1024] ;

int main()
{
    int m;
    cin >> m;
    int h1, h2, m1, m2, s1, s2;
    int temp1, temp2;
    
    for (int i = 0; i < m; i ++)
    {
        scanf("%s %d:%d:%d %d:%d:%d", &per[i].name, &h1, &m1, &s1, &h2, &m2, &s2);
        temp1 = 3600 * h1 + 60 * m1 + s1;
        temp2 = 3600 * h2 + 60 * m2 + s2;
        per[i].etime = temp1;
        per[i].ltime = temp2;
    }

    int min = 102400;
    int max = -1;
    int min_COUNT;
    int max_COUNT;

    for (int i = 0; i < m; i++)
    {
        if (per[i].etime < min)
        {
            min = per[i].etime;
            min_COUNT = i;
        }
        if (per[i].ltime > max)
        {
            max = per[i].ltime;
            max_COUNT = i;
        }
    }

    cout << per[min_COUNT].name << " " << per[max_COUNT].name << endl;
    return 0;
}
