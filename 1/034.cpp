#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret {0x7fffffff, (int)0x80000000};
        int l = 0;
        int l_min = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int curr = nums[mid];
            //cout << "aa " << l << " " << r << " " << mid << endl;
            if (curr == target) {
                if (ret[0] == 0x7fffffff) {
                    l_min = l;
                    ret[0] = min(ret[0], mid);
                }
                ret[1] = max(ret[1], mid);
            }

            if (curr > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        if (ret[0] == 0x7fffffff)
            return vector<int> {-1, -1};

        l = 0;
        r = ret[0];
        while (l <= r) {
            int mid = (l + r) / 2;
            int curr = nums[mid];
            //cout << "bb " << l << " " << r << " " << mid << endl;
            if (curr == target) {
                ret[0] = min(ret[0], mid);
                //ret[1] = max(ret[1], mid);
            }

            if (curr >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return ret;

    }
};

int main() {
    Solution s;
    vector<int> nums {5,7,7,8,8,10};
    cout << "0,1,2,3,4,5" << endl;
    cout << "5,7,7,8,8,10" << endl;
    auto r = s.searchRange(nums, 8);
    cout << r[0] << " " << r[1] << endl;

  return 0;
}
