#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        size_t x = 0, y = height.size() - 1;

        while(y > x) {
            int v = min(height[x], height[y]);
            if (v * (y-x) > max)
                max = v * (y - x);
            if (height[x] < height[y])
                x++;
            else
                y--;
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
