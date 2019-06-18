#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ret, vector<int> &curr, int pos, bool flag = false) {
        if (pos == nums.size()) {
            ret.push_back(curr);
            return;
        }
        solve(nums, ret, curr, pos+1);
        if (pos > 0 && nums[pos] == nums[pos-1] && (!flag)) {
            return;
        }
        curr.push_back(nums[pos]);
        solve(nums, ret, curr, pos+1, true);
        curr.pop_back();

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret{};
        vector<int> curr{};
        sort(nums.begin(), nums.end());
        solve(nums, ret, curr, 0);
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums {1,2,2};
    auto ret = s.subsetsWithDup(nums);
    for (auto comb : ret) {
        for (auto n : comb)
            cout << n << " ";
        cout << endl;
    }


  return 0;
}
