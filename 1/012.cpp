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
    string intToRoman(int num) {
        string s = "";
        int m = num;
        for (auto& rn : rn_dict) {
            //cout << rn.first << " " << rn.second << endl;
            int n = rn.second;
            while(m >= n) {
                s += rn.first;
                m -= n;
            }
        }
        return s;

    }
};

int main() {
    Solution s;
    cout << s.intToRoman(3) << endl;
    cout << s.intToRoman(4) << endl;
    cout << s.intToRoman(9) << endl;
    cout << s.intToRoman(1994) << endl;


  return 0;
}
