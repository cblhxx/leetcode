#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void show(vector<vector<char>>& board) {
        for (auto &line : board) {
            for (auto num : line) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> idxs = {};
        bool u1[9][9]{false}, u2[9][9]{false}, u3[9][9]{false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int idx = i * 9 + j;
                    idxs.push_back(idx);
                    continue;
                }

                int num = board[i][j] - '1';
                int k = i / 3 * 3 + j / 3;
                u1[i][num] = u2[j][num] = u3[k][num] = true;
            }
        }

        int pos = 0;
        while (pos < idxs.size()) {
            int i = idxs[pos] / 9;
            int j = idxs[pos] % 9;
            int k = i / 3 * 3 + j / 3;
            int num = 0;

            //cout << "pos:" << pos  <<" i:" << i << " j:" << j << " v:" << board[i][j]  << endl;
            if (board[i][j] != '.') {
                num = board[i][j] - '1';
                u1[i][num] = u2[j][num] = u3[k][num] = false;
                num++;
            }
            while (num < 9 && (u1[i][num] == true || u2[j][num] == true || u3[k][num] == true)) num++;
            if (num < 9) {
                board[i][j] = num + '1';
                u1[i][num] = u2[j][num] = u3[k][num] = true;
                pos++;
                //cout << "pos:" << pos  <<" i:" << i << " j:" << j << " v:" << board[i][j]  << endl;
                //this->show(board);
            }
            else {
                board[i][j] = '.';
                pos--;
            }
        }
    }
};

int main() {

    vector<vector<char>> matrix{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution s;
    s.solveSudoku(matrix);
    s.show(matrix);

  return 0;
}
