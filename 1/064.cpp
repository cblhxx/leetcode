#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0 || grid[0].size() == 0)
            return 0;
        int m = grid[0].size();
        for (int i = n - 2; i >= 0; i--) {
            grid[i][m-1] += grid[i+1][m-1];
        }
        for (int i = m - 2; i >= 0; i--) {
            grid[n-1][i] += grid[n-1][i+1];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                int num = grid[i][j];
                int a = grid[i+1][j];
                int b = grid[i][j+1];
                //cout << i << " " << j << endl;
                //cout << num << " " << a << " " << b << endl;
                grid[i][j] = std::min(num+a, num+b);
            }
        }
        return grid[0][0];

    }
};

int main() {
    vector<vector<int>> map{{1,3,1}, {1,5,1}, {4,2,1}};
    for (auto &line : map) {
        for (auto num : line) {
            cout << num << " ";
        }
        cout << endl;
    }
    Solution s;
    cout << s.minPathSum(map) << endl;
    for (auto &line : map) {
        for (auto num : line) {
            cout << num << " ";
        }
        cout << endl;
    }

  return 0;
}
