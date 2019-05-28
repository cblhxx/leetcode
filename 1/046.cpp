#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void __permute(vector<int>& nums, vector<vector<int>> &ret, vector<int> &comb, unordered_set<int> &lefts) {
        if (lefts.size() == 1) {
            comb.push_back(*lefts.begin());
            ret.push_back(comb);
            comb.pop_back();
            return;
        }
        for (auto &n : lefts) {
            auto tmp = lefts;
            tmp.erase(tmp.find(n));
            comb.push_back(n);
            this->__permute(nums, ret, comb, tmp);
            comb.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> comb;
        unordered_set<int> lefts;
        for (int i = 0; i < nums.size(); i++) {
            lefts.emplace(nums[i]);
        }

        this->__permute(nums, ret, comb, lefts);
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,3};
    for (auto &line : s.permute(nums)) {
        for (auto n : line) {
            cout << n << " ";
        }
        cout << endl;
    }


  return 0;
}
