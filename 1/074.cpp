#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;

        bool ret = false;
        int n = matrix.size() * matrix[0].size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int i = m / matrix[0].size();
            int j = m % matrix[0].size();

            //cout << l << " " << r << " " << m << " " << matrix[i][j] << endl;
            if (matrix[i][j] == target)
                return true;

            if (matrix[i][j] < target)
                l = m + 1;
            else
                r = m - 1;

        }

        return ret;
    }
};

int main() {
    Solution s;
    //vector<vector<int>> matrix {{1,3,5,7}, {10, 11, 12, 13}};
    vector<vector<int>> matrix {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
    cout << s.searchMatrix(matrix, 1) << endl;
    cout << s.searchMatrix(matrix, 3) << endl;
    cout << s.searchMatrix(matrix, 13) << endl;


  return 0;
}
