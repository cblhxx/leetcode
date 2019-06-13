#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m = 0;

        while(l < r && m < r) {
            while (l < r && nums[l] == 0) l++;
            while (l < r && nums[r] == 2) r--;
            if (l < r && (nums[l] == 2 || nums[r] == 0)) {
                swap(nums[l], nums[r]);
                continue;
            }
            if (m <= l)
                m = l + 1;
            while (m < r && nums[m] == 1) m++;
            if (m < r && nums[m] == 0)
                swap(nums[l], nums[m]);
            else if (m < r && nums[m] == 2)
                swap(nums[r], nums[m]);
        }
    }
};

int main() {
    vector<int> nums {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
    for (auto n : nums) 
        cout << n << " ";
    cout << endl;


  return 0;
}
