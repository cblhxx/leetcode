#include <iostream>

using namespace std;


class Solution {
public:
    bool __isMatch(const string& s, const string& p, int x, int y, int *dp) {
        //cout << s << " " << p << " " << x << " " << y << endl;
        if (x == s.size()) {
            if (y == p.size())
                return true;
            if (p.size() - y >= 2 && p[y+1] == '*')
                return __isMatch(s, p, x, y+2, dp);
            return false;
        }
        int idx = x * (p.size()) + y;
        //cout << idx << endl;

        if (y == p.size())
            return false;

        if (dp[idx] == 1)
            return true;
        if (dp[idx] == -1)
            return false;

        bool f_match = (s[x] == p[y] || p[y] == '.');
        //cout << f_match << endl;
        if (f_match) {
            bool result;
            if (p.size() - y >= 2 && p[y+1] == '*')
                result = (__isMatch(s, p, x+1, y, dp) || __isMatch(s, p, x, y+2, dp));
            else
                result = __isMatch(s, p, x+1, y+1, dp);
            if (result)
                dp[idx] = 1;
            else
                dp[idx] = -1;
            return result;
        }
        //cout << "aa" <<  f_match << endl;

        if (p.size() - y >= 2 && p[y+1] == '*') {
            bool result = __isMatch(s, p, x, y+2, dp);
            if (result)
                dp[idx] = 1;
            else
                dp[idx] = -1;
            return result;
        }
        return false;
    }

    bool isMatch(string s, string p) {
        size_t l = (s.size() + 1) * (p.size() + 1);

        cout << "len:" << l << ", l1:" << s.size() << ", l2:" << p.size()  << endl;
        int* dp = new int[l];

        bool result = __isMatch(s, p, 0, 0, dp);
        delete[] dp;
        return result;
    }
};


int main() {
    Solution s;
    cout << s.isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*") << endl;
    //cout << s.isMatch("aaa", ".*") << endl;


  return 0;
}
