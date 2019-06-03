#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    void solve(int n, int pos, int nq, vector<vector<int>> &matrix, vector<vector<string>> &ret) {
        /*
        cout << n << " " << pos << " " << nq << endl;
        for (auto &l : m) {
            for (auto& num : l) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        if (nq == n) {
            vector<string> res;
            for (int i = 0; i < n; i++) {
                string str;
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == -1)
                        str.push_back('Q');
                    else
                        str.push_back('.');
                }
                res.push_back(str);
            }
            ret.push_back(res);
        }

        for (int i = pos; i < n * n; i++) {
            int y = i / n;
            int x = i % n;
            if (matrix[y][x] != 0)
                continue;
            //vector<vector<int>> matrix = m;
            matrix[y][x] = -1;
            for (int r = 0; r < n; r++)
                if (r != y) matrix[r][x]++;
            for (int c = 0; c < n; c++)
                if (c != x) matrix[y][c]++;
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                int dist = std::abs(x - j);
                int y1 = y - dist;
                int y2 = y + dist;
                if (y1 >= 0)
                    matrix[y1][j]++;
                if (y2 < n)
                    matrix[y2][j]++;
            }
            //cout << i << " " << y << " " << x  << " " << matrix[y][x]<< endl;
            this->solve(n, (i + n) / n * n, nq + 1, matrix, ret);
            matrix[y][x] = 0;
            for (int r = 0; r < n; r++)
                if (r != y) matrix[r][x]--;
            for (int c = 0; c < n; c++)
                if (c != x) matrix[y][c]--;
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                int dist = std::abs(x - j);
                int y1 = y - dist;
                int y2 = y + dist;
                if (y1 >= 0)
                    matrix[y1][j]--;
                if (y2 < n)
                    matrix[y2][j]--;
            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<vector<string>> ret = {};

        this->solve(n, 0, 0, matrix, ret);
        return ret;
    }
};

int main() {
    Solution s;
    auto ret = s.solveNQueens(4);
    for( auto &r : ret) {
        for (auto &str: r) {
            cout << str << endl;
        }
        cout << endl;
    }

  return 0;
}
