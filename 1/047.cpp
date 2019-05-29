#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void __permuteUnique(vector<int> &nums, vector<vector<int>>& ret, int begin) {
        /*
        cout << "begin:" << begin << endl;
        for (auto n : nums) {
            cout << n << " ";
        }
        cout << endl;
        */
        if (begin == nums.size() - 1) {
            //cout << "push back" << endl;
            ret.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            int j = i - 1;
            while (j >= begin && nums[j] != nums[i]) j--;
            if (i == begin || j == begin - 1) {// && nums[i] != nums[i-1]) {
                swap(nums[begin], nums[i]);
                this->__permuteUnique(nums, ret, begin+1);
                swap(nums[i], nums[begin]);
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret{};
        //sort(nums.begin(), nums.end());

        //ret.push_back(nums);
        this->__permuteUnique(nums, ret, 0);
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1, -1, 0, 0, 1, 1, 2};
    //vector<int> nums{1,2,2,1};
    for (auto &line : s.permuteUnique(nums)) {
        for (auto n : line) {
            cout << n << " ";
        }
        cout << endl;
    }


  return 0;
}
