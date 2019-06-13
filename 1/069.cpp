#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int ret = 0;
        while (ret * ret <= x) ret++;

        return ret - 1;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(4) << endl;
    cout << s.mySqrt(8) << endl;


  return 0;
}
