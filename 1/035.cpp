#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            //cout << l << " " << r << endl;
            int num = nums[mid];
            if (num >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 3, 5, 6};
    cout << s.searchInsert(nums, 0) << endl;
    cout << s.searchInsert(nums, 1) << endl;
    cout << s.searchInsert(nums, 2) << endl;
    cout << s.searchInsert(nums, 3) << endl;
    cout << s.searchInsert(nums, 4) << endl;
    cout << s.searchInsert(nums, 5) << endl;
    cout << s.searchInsert(nums, 6) << endl;
    cout << s.searchInsert(nums, 7) << endl;


  return 0;
}
