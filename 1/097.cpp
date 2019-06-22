#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int l1, int l2, vector<vector<int>> &dp) {
        if (l1 == s1.length() && l2 == s2.length())
            return true;
        if (dp[l1][l2] == 1)
            return true;
        if (dp[l1][l2] == -1)
            return false;

        char c = s3[l1+l2];
        bool ret = false;
        if (l1 < s1.length() && s1[l1] == c)
            ret |= solve(s1, s2, s3, l1+1, l2, dp);
        if (!ret && l2 < s2.length() && s2[l2] == c)
            ret |= solve(s1, s2, s3, l1, l2+1, dp);

        if (ret)
            dp[l1][l2] = true;
        else
            dp[l1][l2] = false;

        return ret;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length())
            return false;

        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        return solve(s1, s2, s3, 0, 0, dp);
    }
};

int main() {
    Solution s;
    cout << s.isInterleave("aabc", "dbbcab", "aadbbcbcac") << endl;
    cout << s.isInterleave("aabc", "dbbcac", "aadbbcbcac") << endl;


  return 0;
}
