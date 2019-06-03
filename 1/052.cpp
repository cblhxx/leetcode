#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int max = nums[0];
        int curr = max;

        while (r < nums.size() - 1) {
            //cout << l << " " << r  << " " << max << " "<< curr<< endl;
            if (curr <= 0) {
                l = r = l + 1;
                curr = 0;
            }
            else {
                r++;
            }
            curr += nums[r];
            max = std::max(curr, max);
        }
        return max;
    }
};

int main() {
    Solution s;
    cout << "-2, 1, -3, 4, -1 , 2, 1, -5, 4" << endl;
    vector<int> nums = {-2, 1, -3, 4, -1 , 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;

  return 0;
}
