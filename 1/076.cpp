#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    inline bool is_match(unordered_map<char, int> &curr, unordered_map<char, int> &target, const string &s, string &ret, int l, int r, int &minl) {
        for (auto &pair : target) {
            if (curr[pair.first] < pair.second)
                return false;
        }
        if (r - l + 1< minl) {
            minl = r - l + 1;
            ret = s.substr(l, r - l + 1);
        }

        return true;
    }
    string minWindow(string s, string t) {
        int l = 0, r = 0, minl = INT_MAX;
        unordered_map<char, int> target;
        unordered_map<char, int> curr;
        string ret = "";

        for (auto c : t) {
            target[c]++;
        }

        while (l < s.length() && (target.find(s[l]) == target.end() && curr.size() == 0)) l++;
        r = l;
        while (r < s.length() && l < s.length()) {
            //cout << l << " " << r << endl;
           if (target.find(s[r]) != target.end()) {
               curr[s[r]]++;
               if (is_match(curr, target, s, ret, l, r, minl)) {
                   if (minl == t.length())
                       return ret;
                   while (l < r && is_match(curr, target, s, ret, l, r, minl)) {
                       if (target.find(s[l]) != target.end())
                           curr[s[l]]--;
                       l++;
                   }
                   while(l < r && target.find(s[l]) == target.end()) l++;
               }
           }
           r++;
        }

        return ret;
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.minWindow("ADOBECODEBANC", "AABC") << endl;
    cout << s.minWindow("ADOBECODEBANC", "ABBC") << endl;
    cout << s.minWindow("ADOBECODEBANC", "ABCC") << endl;


  return 0;
}
