#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0)
            return 0;
        int m = obstacleGrid[0].size();
        vector<vector<uint64_t>> map(n, vector<uint64_t>(m, 0));
        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1)
                    continue;
                if (i == n-1 && j == m-1) {
                    map[i][j] = 1;
                    continue;
                }
                uint64_t a = (i == n - 1? 0: map[i+1][j]);
                uint64_t b = (j == m - 1? 0: map[i][j+1]);
                map[i][j] = a + b;
            }
        }
        //map[n-1][m-1] = 1 - obstacleGrid[n-1][m-1];
        return map[0][0];
    }
};

int main() {
    vector<vector<int>> map {{0,0,0}, {0,1,0}, {0,0,0}};
    Solution s;
    cout << s.uniquePathsWithObstacles(map) << endl;;


  return 0;
}
