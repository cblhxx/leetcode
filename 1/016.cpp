#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());

        int ret = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); i++) {
            int goal = target - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                //cout << i << " " << l << " " << r << " " << goal << endl;
                int num2 = nums[l];
                int num3 = nums[r];
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(ret - target)) {
                    ret = sum;
                }
                if (num2 + num3 < goal)
                    while(l < r && nums[l] == num2) l++;
                if (num2 + num3 > goal)
                    while(l < r && nums[r] == num3) r--;
                if (num2 + num3 == goal)
                    return target;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,6,9,14,16,70};
    cout << s.threeSumClosest(nums, 81) << endl;


  return 0;
}
