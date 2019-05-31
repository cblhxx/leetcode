#include <iostream>
#include <unordered_map>

using namespace std;

//#define INT_MIN 0x80000000
class Solution {
public:
    double __myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == 2)
            return x * x;

        double y = __myPow(x, n / 2);
        y = y * y;
        if (n % 2 > 0)
            y = y * x;
        return y;
    }
    double myPow(double x, int n) {
        bool negtive = false;
        bool underflow = false;
        if (n == 0)
            return 1;

        if (x == 1)
            return 1;
        if (n < 0) {
            negtive = true;
            if (n == INT_MIN) {
                underflow = true;
                n = INT_MAX;
            }
            else {
                n = 0 - n;
            }
        }

        double ret = __myPow(x, n);
        /*dd
        double ret = x;
        while(n > 1) {
            if (ret == 0)
                return 0;
            ret *= x;
            n--;
        }
        */
        ret = negtive? 1 / ret: ret;
        return underflow? ret*x: ret;
    }
};


int main() {
    Solution s;
    cout << s.myPow(2, 3) << endl;
    cout << s.myPow(2, -3) << endl;
    cout << s.myPow(2, -2147483648) << endl;


  return 0;
}
