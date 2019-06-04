#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0)
            return true;

        int dist = nums[0];
        int i = 1;
        while (i < nums.size() && i <= dist) {
            if (i + nums[i] > dist)
                dist = i + nums[i];
            i++;
        }
        cout << i << " " << dist << endl;
        return dist >= nums.size() - 1;
    }
};

int main() {
    Solution s;
    //vector<int> nums {2,3,1,1,4};
    vector<int> nums {3,2,1,0,4};
    cout << s.canJump(nums) << endl;


  return 0;
}
