#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n == 0) {
            ret.push_back("");
            return ret;
        }
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = n - 1 - i;
            for (auto &lstr : this->generateParenthesis(left)) {
                for (auto &rstr : this->generateParenthesis(right)) {
                    for (int j = 0; j < 2; j++) {
                        string str;
                        if (j == 0)
                            str = "(" + lstr + ")" + rstr;
                        else
                            str = lstr + "(" + rstr + ")";
                        int k = 0;
                        for (k = 0; k < ret.size(); k++) {
                            if (ret[k] == str) {
                                break;
                            }
                        }
                        if (k == ret.size()) {
                            ret.push_back(str);
                        }
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    for (auto &str : s.generateParenthesis(3)) {
        cout << str << endl;
    }

  return 0;
}
