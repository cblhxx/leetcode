#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        vector<bool> dp(heights.size(), false);
        for (int i = 0; i < heights.size(); i++) {
            int l = i, r = i, height = heights[i];
            if (dp[i] == true)
                continue;
            while (l-1 >= 0 && heights[l-1] >= height) l--;
            while (r+1 < heights.size() && heights[r+1] >= height) r++;
            max_area = max(max_area, height * (r - l + 1));
            for (int j = l; j <= r; j++) {
                if (heights[j] == height)
                    dp[j] = true;
            }
            //cout << l << " " << r << " " << max_area << endl;
        }
        return max_area;
    }
};

int main() {
    Solution s;
    vector<int> heights {2,1,5,6,2,3};
    cout << s.largestRectangleArea(heights) << endl;


  return 0;
}
