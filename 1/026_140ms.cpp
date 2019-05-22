#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            int j = i - 1;
            while (j >= 0 && nums[j] == nums[i]) j--;
            if (j != i - 1) {
                vector<int>::iterator last, first;
                last = nums.begin() + i;
                first = nums.begin() + j + 1;
                nums.erase(first, last);
                i = j + 1;
            }
        }
        return nums.size();

    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0,0,1,1,2,2,3,4};
    for (int i = 0; i < s.removeDuplicates(nums); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

  return 0;
}
