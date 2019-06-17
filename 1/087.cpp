#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool _isScramble(string s1, string s2, int begin1, int begin2, int length) {
        string a = s1.substr(begin1, length);
        string b = s2.substr(begin2, length);
        if (a == b)
            return true;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b)
            return false;

        if (length <= 3) {
            if (a == b)
                return true;
            return false;
        }

        bool ret = false;
        for (int p1 = 1; p1 < length; p1++) {
        int p2 = length - p1;
        if (!ret)
            ret = (_isScramble(s1, s2, begin1, begin2, p1) &&
                   _isScramble(s1, s2, begin1 + p1, begin2 + p1, p2));
        if (!ret)
            ret = (_isScramble(s1, s2, begin1, begin2 + p2, p1) &&
                   _isScramble(s1, s2, begin1 + p1, begin2, p2));
        }
        return ret;
    }

    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        return _isScramble(s1, s2, 0, 0, s1.length());
    }
};

int main() {
    Solution s;

    cout << s.isScramble("great", "rgeat") << endl;
    cout << s.isScramble("abcde", "caebd") << endl;


  return 0;
}
