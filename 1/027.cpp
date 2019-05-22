#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == val)
                continue;
            nums[i] = nums[j];
            i++;
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0,0,2,2,1,1,2,2,3,4};
    int len = s.removeElement(nums, 2);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

  return 0;
}
