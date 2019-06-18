#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int solve(string& s, int l, vector<int>& dp) {
        if (l < s.length() &&s[l] == '0')
            return 0;
        if (l == s.length() - 1)
            return 1;
        if (l == s.length())
            return 1;
        if (dp[l] > 0)
            return dp[l];

        int ret = 0;
        ret = solve(s, l+1, dp);
        if (l < s.length() - 1) {
            if (s[l] == '1' || (s[l] == '2' && s[l+1] <= '6'))
                ret += solve(s, l+2, dp);
        }
        dp[l] = ret;
        return ret;
    }
    int numDecodings(string s) {
        if (s.length() == 0)
            return 0;
        vector<int> dp(s.length());
        return solve(s, 0, dp);
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("226") << endl;


  return 0;
}
