#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            //cout << j << " " << nums[j] << " " << endl;
            while (nums[j] > 0 && nums[j] <= nums.size() && nums[nums[j]-1] != nums[j]) {
              //cout << "ff" << endl;
                int v = nums[j] - 1;
                if (v >= 0 && v < nums.size()) {
                    //cout << "swap " << v << " " << j << endl;
                    swap(nums[v], nums[j]);
                }
            }
        }

        int idx = 0;
        while(idx < nums.size() && nums[idx] == idx+1)  idx++;
        return idx+1;
    }
};

int main() {
    vector<int> nums {2, 1};
    Solution s;
    cout << s.firstMissingPositive(nums) << endl;

  return 0;
}
