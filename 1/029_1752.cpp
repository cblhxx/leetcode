#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int ret = 0;
        int overflow = 0;
        bool negtive = false;
        if (divisor == 0)
            return -1;
        if (dividend == 0)
            return 0;
        if (dividend == divisor)
            return 1;
        if (divisor == 1)
            return dividend;
        if (divisor == -1 && dividend == ((int)0x80000000))
            return 0x7fffffff;
        if (divisor == -1)
            return 0-dividend;
        if (dividend < 0) {
            if (dividend == ((int)0x80000000)) {
                dividend += 1;
                overflow = 1;
            }
            dividend = 0 - dividend;
            negtive = !negtive;
        }
        if (divisor < 0) {
            if (divisor == ((int)0x80000000)) {
                return 0;
            }
            divisor = 0 - divisor;
            negtive = !negtive;
        }
        if (negtive && (dividend - divisor == 0))
            return -1;

        while ((divisor & 1) != 1) {
            dividend = dividend >> 1;
            divisor = divisor >> 1;
            dividend += overflow;
            overflow = 0;
        }

        if (divisor == 1)
            return negtive? -dividend : dividend;

        //cout << dividend << " " << divisor << endl;
        while (dividend >= divisor) {
            ret++;
            dividend -= divisor;
            dividend += overflow;
            overflow = 0;
        }
        if (negtive)
            ret = 0 - ret;

        return ret;
    }
};

int main() {
    Solution s;
    cout << s.divide(5, 2) << endl;


  return 0;
}
