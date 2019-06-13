#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ret, int n) {
        if (n <= 0) {
            ret.push_back(vector<int>{});
            return;
        }
        solve(nums, ret, n-1);
        int len = ret.size();
        for (int i = 0; i < len; i++) {
            ret.push_back(ret[i]);
            ret.back().push_back(nums[n-1]);
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        solve(nums, ret, nums.size());

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,3};
    auto combs = s.subsets(nums);
    for (auto comb : combs) {
        for (auto n : comb) {
            cout << n << " ";
        }
        cout << endl;
    }


  return 0;
}
