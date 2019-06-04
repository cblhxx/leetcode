#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0, r = s.size()-1;
        while (r >= 0 && s[r] == ' ') r--;
        if (r < 0)
            return 0;
        l = r - 1;
        while (l >= 0 && s[l] != ' ') l--;
        return r - l;
    }
};


int main() {
    Solution s;
    cout << s.lengthOfLastWord("hello world") << endl;

  return 0;
}
