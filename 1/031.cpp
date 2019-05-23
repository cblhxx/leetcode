#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;

        auto iter = nums.rbegin();
        int num = *iter;
        for (iter = nums.rbegin(); iter != nums.rend(); iter++) {
            //cout << *iter << endl;
            if (*iter < num)
                break;
            num = *iter;
        }

        if (iter != nums.rend()) {
            int tmp = 0;
            auto target = nums.rbegin();
            while (*target <= *iter) target++;
            tmp = *iter;
            *iter = *target;
            *target = tmp;

            sort(nums.rbegin(), iter, greater<int>());
        }
        else {
            //cout << "bb" << endl;
            sort(nums.begin(), nums.end());
        }

    }
};

int main() {
    Solution s;
    vector<int> nums {3,6,7,2,1,1};
    s.nextPermutation(nums);
    for (auto n : nums) {
        cout << n << " ";
    }
    cout << endl;



  return 0;
}
