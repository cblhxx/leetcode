#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 2;
        if (n < 3)
            return n;

        while(n-- > 2) {
            first = first + second;
            swap(first, second);
        }
        return second;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(2) << endl;
    cout << s.climbStairs(3) << endl;


  return 0;
}
