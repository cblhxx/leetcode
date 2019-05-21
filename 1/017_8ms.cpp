#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> pmap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret = {};
        size_t len = digits.length();
        if (len == 0) {
            return ret;
        }

        int digit = digits[len-1] - '2';
        auto vec = letterCombinations(digits.substr(0, len-1));
        if (vec.size() == 0)
            vec.push_back("");
        for (auto& str : vec) {
            for (auto& c : pmap[digit]) {
                ret.push_back(str + c);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    auto vec = s.letterCombinations("23");
    for (auto &comb : vec) {
        cout << comb << endl;
    }


  return 0;
}
