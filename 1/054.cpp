#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret {};
        if (matrix.size() == 0)
            return ret;
        int left = 0, top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int x = 0, y = 0;

        while(left <= right) {
            for(x = left, y = top; x <= right; x++) {
                ret.push_back(matrix[y][x]);
            }
            if (++top > bottom)
                break;
            for(x = right, y = top; y <= bottom; y++) {
                ret.push_back(matrix[y][x]);
            }
            if (--right < left)
                break;
            for(x = right, y = bottom; x >= left; x--) {
                ret.push_back(matrix[y][x]);
            }
            if (--bottom < top)
                break;
            for(x = left, y = bottom; y >= top; y--) {
                ret.push_back(matrix[y][x]);
            }
            left++;
        }

        return ret;
    }
};

int main() {
    Solution s;
    //vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> nums = {{1,2,3}};
    auto ret = s.spiralOrder(nums);
    for (auto num : ret) {
        cout << num << " ";
    }
    cout << endl;

  return 0;
}
