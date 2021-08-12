//
//  main.cpp
//  leetcode_excel
//
//  Created by California Institute of Technology on 2/9/21.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        vector<char>rst;
        string rs;
        while (n > 0) {
            n -= 1;
            rst.push_back('A' + (n % 26));
            n /= 26;
        }
        reverse(rst.begin(), rst.end());
        rs.assign(rst.begin(), rst.end());
        return rs;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.convertToTitle(701) << endl;
    return 0;
}
