#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (auto j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
            if (result.size() > 0)
                break;
        }
        return result;
    }
};

int main() {
    Solution s;
    //vector<int> nums = {2,7,11,15};
    vector<int> nums = {2,11,15,7};
    auto r = s.twoSum(nums, 9);
    std::cout << r[0] << " " << r[1] << std::endl;


    return 0;
}
