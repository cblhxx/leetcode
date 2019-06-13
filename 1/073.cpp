#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.emplace(i);
                    cols.emplace(j);
                }
            }
        }

        for (auto i : rows) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = 0;
            }
        }
        for (auto j : cols) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }

    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix {{0,1,2,0}, {3,4,5,2}, {1,2,3,4}};
    s.setZeroes(matrix);
    for (auto &l : matrix) {
        for (auto n : l) {
            cout << n << " ";
        }
        cout << endl;
    }


  return 0;
}
