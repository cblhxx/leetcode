#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int first_max = 0;
        size_t n = height.size();
        if (n < 2)
            return 0;

        for (int i = 0; i < n - 1; i++) {
            if (height[i] == 0)
                continue;

            if (height[i] <= first_max)
                continue;

            for (int j = i + ceil((max+1) / height[i]); j < n; j++) {
                int m = std::min(height[i], height[j]) * (j - i);
                if (m > max) {
                    first_max = height[i];
                    max = m;
                }
            }
        }

        return max;
    }
};

int main() {
    Solution s;
    vector<int> nums {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(nums) << endl;
    //cout << s.maxArea(vector<int>{1,8,6,2,5,4,8,3,7}) << endl;

  return 0;
}
