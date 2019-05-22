#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int l = 0; l < nums.size(); ) {
            int r = l + 1;
            if (i != l)
                nums[i] = nums[l];
            i++;

            while (r < nums.size() && nums[l] == nums[r]) r++;
            l = r;
        }
        return i;

    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0,0,1,1,2,2,3,4};
    int len = s.removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

  return 0;
}
