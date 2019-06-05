#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret (n, vector<int>(n, 0));
        int top = 0, left = 0;
        int bottom = n - 1, right = n - 1;
        int x = 0, y = 0;
        int num = 1;
        while(left <= right && top <= bottom) {
            while(x <= right) {
                ret[y][x++] = num++;
            }
            x = right;
            y = ++top;
            while(y <= bottom) {
                ret[y++][x] = num++;
            }
            x = --right;
            y = bottom;
            while(x >= left) {
                ret[y][x--] = num++;
            }
            x = left;
            y = --bottom;
            while (y >= top) {
                ret[y--][x] = num++;
            }
            x = ++left;
            y = top;
        }

        return ret;
    }
};

int main() {
    Solution s;
    auto ret = s.generateMatrix(5);
    for (auto row: ret) {
        for (auto num: row) {
            cout << num << " ";
        }
        cout << endl;
    }


  return 0;
}
