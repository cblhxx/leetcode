#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isMatch(string &s, string &p, int ls, int lp, unordered_map<int, bool> &dp) {
        //cout << s << " " << p << " " << ls << " " << lp << endl;
        bool result = false;
        int idx = ls * (p.length() + 1) + lp;
        if (dp.find(idx) != dp.end()) {
            return dp[idx];
        }
        if (ls == s.length() && lp == p.length()) {
            result = true;
        }
        else if (ls == s.length()) {
            while(lp < p.length() && p[lp] == '*') lp++;
            if (lp == p.length())
                result = true;
        }
        else if (lp == p.length()) {
            result = false;
        }
        else if (s[ls] == p[lp] || p[lp] == '?') {
            //cout << "match " << s << " " << p << " " << ls << " " << lp << endl;
            result = isMatch(s, p, ls+1, lp+1, dp);
        }
        else if (p[lp] == '*') {
            while (lp + 1 < p.size() && p[lp+1] == '*') lp++;
            result = (isMatch(s, p, ls, lp+1, dp) || isMatch(s, p, ls+1, lp, dp));
        }
        dp[idx] = result;
        return result;
    }
    bool isMatch(string s, string p) {
        unordered_map<int, bool> dp;
        return this->isMatch(s, p, 0, 0, dp);
    }
};

int main() {
    Solution s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("dceb", "*b") << endl;
    cout << s.isMatch("acdcb", "a*c?b") << endl;
    cout << s.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;
    cout << s.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaab", "a****************b") << endl;

  return 0;
}
