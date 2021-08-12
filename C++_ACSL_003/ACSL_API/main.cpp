#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int main(){
    
    //1//string to long;
    //1//using -> <stblib.h>
    string a;
    cout << "string -> long; input a string with numbers: ";
    cin >> a;
    long b = stol(a);
    cout << b << endl;
    
    //2//order every characters in a string
    string c;
    cout << "order string; input a string: ";
    cin >> c;
        /*
         Really important.
         Change string to const char*;
         Change const char* to char*;
         */
    const char* ne = c.data();
    char* ch = new char[strlen(ne)+1];
    strcpy(ch, ne);
    for (int i = 0; i < c.length(); i ++){
        for (int j = i+1; j < c.length(); j ++){
            if (ch[i] <= ch[j]){
            }
            else{
                char tmp = ch[i];
                ch[i] = ch[j];
                ch[j] = tmp;
            }
        }
    }
        // change char* to string.
    c.assign(ch);
    cout << "The string is now changed;\n" << c << endl;
    cout << "Length: " << c.length() << endl;
    
    //3//vector<char( or string)> to string
    vector<char>ss;//vector<string>ss as well;
    ss.push_back('A');
    stringstream ssrst;
    string str;
    copy(ss.begin(),ss.end(),ostream_iterator<char>(ssrst,""));
    str=ssrst.str();
    cout << str << endl;
    
    return 0;
}
