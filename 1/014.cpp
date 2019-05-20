#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      int i = 0;
      int len = 0x7fffffff;
      if (strs.size() == 0)
        return "";
      if (strs.size() == 1)
        return strs[0];
      for (auto& str : strs) {
        len = min(len, ((int)str.size()));
      }
      while (i < len) {
        char ch = strs[0][i];
        int j = 1;
        while (j < strs.size()) {
          if (strs[j][i] != ch)
            break;
          j++;
        }
        if (j < strs.size())
          break;
        i++;
      }
      return strs[0].substr(0, i);
    }
};

int main() {
  Solution s;
  vector<string> strs {"abc", "ab"};

  cout << s.longestCommonPrefix(strs) << endl;


  return 0;
}
