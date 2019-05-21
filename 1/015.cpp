#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (r > l) {
                int sum = nums[l] + nums[r];
                if (sum > target)
                    r--;
                else if (sum < target)
                    l++;
                else {
                    int num2 = nums[l];
                    int num3 = nums[r];
                    ret.push_back(vector<int>{nums[i], num2, num3});
                    while (l < r && nums[l] == num2) l++;
                    while (l < r && nums[r] == num3) r--;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i+1])
                i++;
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> tmp{-1,0,1,2,-1,-4};
    vector<vector<int>> r = s.threeSum(tmp);
    for (auto &i : r) {
        for (auto &n : i)
            cout << n << " ";
        cout << endl;
    }

  return 0;
}
