#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> map(n, vector<int>(m, 0));
        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (i == n -1 || j == m-1) {
                    map[i][j] = 1;
                }
                else {
                    int a = map[i+1][j];
                    int b = map[i][j+1];
                    map[i][j] = a + b;
                }
                //cout << i << " " << j << " " << map[i][j] << endl;
            }
        }
        return map[0][0];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(7, 3) << endl;;


  return 0;
}
