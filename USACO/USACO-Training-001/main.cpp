/*
ID: z2047ds1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(){
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string str1;
    string str2;
    fin >> str1; fin >> str2;
    long sum1 = 1;
    long sum2 = 1;
    for (int i = 0; i < str1.length(); i++){
        sum1*=(str1[i]-64);
    }
    for (int i = 0; i < str2.length(); i++){
        sum2*=(str2[i]-64);
    }
    
    if(sum1%47 == sum2%47){
        fout << "GO\n";
    }
    else{
        fout << "STAY\n";
    }
    return 0;
}
