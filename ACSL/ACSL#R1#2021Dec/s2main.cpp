#include <iostream>
#include <cstring>

using namespace std;

int toSecond(int siz){
    return siz*5;
}
int toMinute(int siz){
    return siz*60*5;
}
int toHour(int siz){
    return siz*60*60;
}
int parse(char co,int siz){
    int sec=0;
    switch (co)
    {
    case 'R':
        sec += toHour(siz);
        break;
    case 'G':
        sec += toMinute(siz);
        break;
    case 'B':
        sec += toSecond(siz);
        break;
    case 'Y':
        sec += toHour(siz);
        sec += toMinute(siz);
        break;
    case 'M':
        sec += toHour(siz);
        sec += toSecond(siz);
        break;
    case 'C':
        sec += toMinute(siz);
        sec += toSecond(siz);
        break;
    default:
        break;
    }
    return sec;
}
string toClock(int sec){
    int ss = sec % 60;
    sec /= 60;
    int mm = sec % 60;
    sec /= 60;
    int hh = sec;
    hh %= 12;

    char tmp[20];
    sprintf(tmp,"%02d:%02d:%02d",hh,mm,ss);
    string ret = tmp;
    return ret;
}
int main(){
    string color;
    cin >> color;
    int siz[5] = {1,1,2,3,5};
    int sec = 0;
    for(int i = 0; i < 5; i ++){
        sec += parse(color[i], siz[i]);
    }

    string clock = toClock(sec);
    cout << clock << endl;
    return 0;
}
