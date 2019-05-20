#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<string, int>> rn_dict = {
  {"M", 1000},
  {"CM", 900},
  {"D", 500},
  {"CD", 400},
  {"C", 100},
  {"XC", 90},
  {"L", 50},
  {"XL", 40},
  {"X", 10},
  {"IX", 9},
  {"V", 5},
  {"IV", 4},
  {"I", 1}
};

class Solution {
  public:
    int romanToInt(string s) {
      int n = 0;
      int i = 0, j = 0;
      while (i < s.size() && j < rn_dict.size()) {
        string rstr = rn_dict[j].first;
        int value = rn_dict[j].second;
        int keysize = rstr.size() - 1;
        while (keysize >= 0) {
          if (s[i+keysize] != rstr[keysize]) {
            j++;
            break;
          }
          keysize--;
        }
        if (keysize >= 0) {
          continue;
        }

        n += value;
        i += rstr.size();
      }
      return n;

    }
};

int main() {
  Solution s;
  cout << s.romanToInt("XCIV") << endl;
  cout << s.romanToInt("MCMXCIV") << endl;


  return 0;
}
