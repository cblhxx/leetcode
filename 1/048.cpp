#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n - i * 2 - 1; j++) {
                //cout << i << " " << j << endl;
                int x0 = i;
                int y0 = i;
                int x1 = x0;
                int y1 = y0 + j;
                int x2 = x0 + j;
                int y2 = n - 1 - y0;
                int x3 = n - 1 - x0;
                int y3 = n - 1 - y0 - j;
                int x4 = n - 1 - x0 - j;
                int y4 = y0;

                /*
                cout << x1 << " " << y1 << endl;
                cout << x2 << " " << y2 << endl;
                cout << x3 << " " << y3 << endl;
                cout << x4 << " " << y4 << endl;
                */
                int tmp = matrix[x1][y1];
                matrix[x1][y1] = matrix[x4][y4];
                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = tmp;
            }
        }
    }
};

int main() {
    vector<vector<int>> nums = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    for (auto &l : nums) {
        for (auto n : l)
            cout << n << " ";
        cout << endl;
    }
    Solution s;
    s.rotate(nums);
    for (auto &l : nums) {
        for (auto n : l)
            cout << n << " ";
        cout << endl;
    }


  return 0;
}
