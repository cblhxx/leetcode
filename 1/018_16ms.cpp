#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret {};
        size_t len = nums.size();
        if (len < 4)
            return ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 3; i++) {
            for (int j = i + 1; j < len - 2; j++) {
                int goal = target - nums[i] - nums[j];
                int l = j + 1;
                int r = len - 1;
                if (goal > nums[r] + nums[r-1])
                    continue;
                if (goal < nums[l] + nums[l+1])
                    continue;
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    int num3 = nums[l];
                    int num4 = nums[r];
                    if (sum < goal)
                        l++;
                    else if (sum > goal)
                        r--;
                    else {
                        vector<int> comb = {nums[i], nums[j], nums[l], nums[r]};
                        ret.push_back(comb);
                        while (l < r && nums[l] == num3) l++;
                        while (l < r && nums[r] == num4) r--;
                    }
                }
                while (j < len - 2 && nums[j] == nums[j+1]) j++;
            }
            while (i < len - 3 && nums[i] == nums[i+1]) i++;
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums {1, 0, -1, 0, -2, 2};
    auto vec = s.fourSum(nums, 0);
    for (auto &comb : vec) {
        for (auto &n : comb) {
            cout << n << " ";
        }
        cout << endl;
    }

  return 0;
}
