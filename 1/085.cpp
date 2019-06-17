#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> height) {
        int ret = 0;
        height.push_back(0);
        vector<int> index;

        for(int i = 0; i < height.size(); i++)
        {
            while(index.size() > 0 && height[index.back()] >= height[i])
            {
                int h = height[index.back()];
                index.pop_back();

                int sidx = index.size() > 0 ? index.back() : -1;
                if(h * (i-sidx-1) > ret)
                    ret = h * (i-sidx-1);
            }
            index.push_back(i);
        }

        return ret;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int ret = this->largestRectangleArea(heights);
            area = max(area, ret);
        }
        return area;
    }
};

int main() {
    Solution s;


  return 0;
}
