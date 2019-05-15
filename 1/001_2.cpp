#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            int j = target - nums[i];
            if (map.find(j) == map.end() || map[j] == i) {
                continue;
            }
            result.push_back(i);
            result.push_back(map[j]);
            break;

        }

        return result;
    }
};

int main() {
    Solution s;
    //vector<int> nums = {2,7,11,15};
    //vector<int> nums = {2,11,15,7};
    vector<int> nums = {3, 2, 4};
    auto r = s.twoSum(nums, 6);
    std::cout << r[0] << " " << r[1] << std::endl;


    return 0;
}
