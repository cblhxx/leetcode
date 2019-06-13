#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int count = 1, l = 1, r = 0;
        while (count <= 2 && l < nums.size()) {
            if (nums[l] == nums[l-1])
                count++;
            else
                count = 1;
            l++;
        }
        if (count == 3)
            l--;
        r = l + 1;
        //cout << l << " " << r << endl;
        while (r < nums.size()) {
            if (nums[r] != nums[l]) {
                nums[l] = nums[r];
                nums[l+1] = nums[r];
                count = 1;
                l++;
            }
            else if (count == 1) {
                nums[l] = nums[r];
                nums[l+1] = nums[r];
                l++;
                count++;
            }
            r++;
        }

        return l;
    }
};

int main() {
    Solution s;
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    cout << s.removeDuplicates(nums) << endl;
    for (auto n : nums)
        cout << n << " ";
    cout << endl;


  return 0;
}
