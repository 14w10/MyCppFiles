//
//  main.cpp
//  HEAP_001
//
//  Created by California Institute of Technology on 2/9/21.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x != 0) {
            int p = x % 10;
            x /= 10;
            if (r > INT_MAX/10 || (r == INT_MAX / 10 && p > 7)) return 0;
            if (r < INT_MIN/10 || (r == INT_MIN / 10 && p < -8)) return 0;
            r = r * 10 + p;
        }
        return r;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reverse(123) << endl;
    return 0;
}
