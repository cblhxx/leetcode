#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (r >= l) {
            int mid = (r + l) / 2;
            int curr = nums[mid];
            //cout << target << " " << curr << " " << l << " " << r << " " << mid << endl;
            if (curr == target)
                return mid;
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < curr)
                    r = min(mid+1, r-1);
                else
                    l = max(l+1, mid-1);
                //cout << "aa " << l << " " << r << endl;
            }
            else
            {
                if (target > curr && target <= nums[r])
                    l = max(l+1, mid-1);
                else
                    r = min(r-1, mid+1);
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums{3,1};
    cout << s.search(nums, 1) << endl;

  return 0;
}
