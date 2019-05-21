#include <iostream>
#include <vector>
#include <string>

using namespace std;




class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> pmap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int len = digits.length();
        int count = 1;
        for (int i = 0; i < len; i++) {
            auto digit = digits[i] - '2';
            count *= pmap[digit].length();
        }
        if (count == 1)
            count = 0;
        vector<string> ret(count);

        for (int i = 0; i < count; i++) {
            string str = "";
            int seed = 1;
            for (int j = 0; j < len; j++) {
                auto digit = digits[j] - '2';
                int idx = (i / seed) % pmap[j].length();
                //cout << "i:" << i << " j:" << j << " idx:" << idx << endl;
                str += pmap[j][idx];
                seed *= pmap[j].length();
            }
            ret[i] = (str);
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
