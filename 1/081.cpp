#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool _search(vector<int>& nums, int target, int l, int r) {
        int m = (l + r) / 2;
        bool ret = false;

        //cout << l << " " << r << " " << m << endl;
        if (l > r)
            return false;
        if (nums[m] == target || nums[l] == target || nums[r] == target)
            return true;
        if ((nums[m] > target && target > nums[l]) || nums[m] <= nums[l])
            ret |= _search(nums, target, l, m-1);
        if (!ret && ((nums[m] < target && target < nums[r]) || nums[m] >= nums[r]))
            ret |= _search(nums, target, m+1, r);
        return ret;
    }
    bool search(vector<int>& nums, int target) {
        return _search(nums, target, 0, nums.size() - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums {2,5,6,0,0,1,2};

    for (auto n : {0,1,2,3,4,5,6,7}) {
        cout << n << " " << s.search(nums, n) << endl;
    }

  return 0;
}
