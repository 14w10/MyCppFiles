//
//  main.cpp
//  Sokudo
//
//  Created by eChcalt on 5/26/21.
//

#include <iostream>
#include <vector>
using namespace std;

int sokudo[9][9];
int hole[9][9];
 
bool set(int x, int y, int val)
{
    if (sokudo[y][x] != 0)        //non-Null
        return false;
    int x0, y0;
    for (x0 = 0; x0 < 9; x0 ++)
    {
        if (sokudo[y][x0] == val)    //Contradiction with respect of Line
            return false;
    }
    for (y0 = 0; y0 < 9; y0 ++)
    {
        if (sokudo[y0][x] == val)    //Contradiction with respect of Column
            return false;
    }
    for (y0 = y/3 * 3; y0 < y/3 * 3 + 3; y0 ++)
    {
        for (x0 = x/3 * 3; x0 < x/3 * 3 + 3; x0 ++)
        {
            if (sokudo[y0][x0] == val) //Contradiction with respect of block
                return false;
        }
    }
    sokudo[y][x] = val;
    return true;
}
 
void reset(int m, int n)
{
    sokudo[n][m] = 0;
}
 
void initLine(int* line)    //Initial Line with Random Order.
{
    int i, k, tmp;
    for (i = 0; i < 9; i ++)
    {
        line[i] = i;
    }
    for (i = 0; i < 9; i ++)
    {
        k = rand() % 9;
        tmp = line[k];
        line[k] = line[i];
        line[i] = tmp;
    }
}
 
void SokudoDraw()   //Draw the sokudo
{
    for (int j = 0; j < 9; j ++)
    {
        if(j % 3 == 0){
            cout << " -------------------------\n ";
        }
        else{
            cout << " ";
        }
        cout << "| ";
        for (int i = 0; i < 9; i ++)
        {
            if (hole[j][i] == 0){
                cout << sokudo[j][i] << " ";
            }
            else{
                cout << "  ";
            }
            if (i % 3 == 2){
                cout << "| ";
            }
            else{
                cout << "";
            }
        }
        cout << endl;
    }
    cout << " -------------------------\n";
}

bool fillFrom(int y, int val)
{
    int line[9];
    initLine(line);
    for (int i = 0; i < 9; i ++)
    {
        int x = line[i];
        if (set(x, y, val))
        {
            if (y == 8)
            {
                if (val == 9 || fillFrom(0, val+1))
                    return true;
            }
            else
            {
                if (fillFrom(y+1, val))
                    return true;
            }
            reset(x, y);
            /*
             !!Backtrace!!
             */
        }
    }
    return false;
}

void digHole(int cnt)
{
    int idex[81];
    int i, k;
    for (i = 0; i < 81; i ++)
    {
        hole[i / 9][i % 9] = 0;
        idex[i] = i;
    }
    for (i = 0; i < cnt; i ++)
    {
        k = rand() % 81;
        int tmp = idex[k];
        idex[k] = idex[i];
        idex[i] = tmp;
    }
    for (i = 0; i < cnt; i ++)
    {
        hole[idex[i] / 9][idex[i] % 9] = 1;
    }
}
 
int main()
{
    
    srand((unsigned)time(NULL));
    while (!fillFrom(0, 1)) ;
    int level, dig = 10;
    cout << "Input a integer" << endl;
    cout << "0: Most difficult" << endl;
    cout << "1: Difficult" << endl;
    cout << "2: Less Difficult" << endl;
    cout << "3: Easy" << endl;
    cout<< "Input The Integer: ";
    cin >> level;
    cout << endl;
    switch (level)
        {
        case 0:
            dig = 60;
            break;
        case 1:
            dig = 50;
            break;
        case 2:
            dig = 35;
            break;
        case 3:
            dig = 20;
            break;
        }
    
    digHole(dig);
    SokudoDraw();
    cout << endl;
    cout << "Do you want to see the answer? y/N: ";
    string cor;
    cin >> cor;
    cout << endl;
    if (cor == "y"){
        cout << " -------------------------\n";
        for (int i = 1; i <= 9; i++){
            cout << " | ";
            for (int j = 1; j <= 9; j++){
                cout << sokudo[i-1][j-1] << " ";
                if (j % 3 == 0){
                    cout << "| ";
                }
            }
            cout << endl;
            if(i % 3 == 0){
                cout << " -------------------------\n";
            }
        }
    }
    else{
    }
    return 0;
}
