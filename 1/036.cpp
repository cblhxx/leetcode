#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool rowmap[9][9] = {};
        bool colmap[9][9] = {};
        bool seqmap[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                int k = i / 3  + j / 3 * 3;

                if (rowmap[i][num] || colmap[j][num] || seqmap[k][num]) {
                    cout << rowmap[i][num] << endl;
                    cout << colmap[j][num] << endl;
                    cout << seqmap[k][num] << endl;
                    cout << i << " " << j << " " << num+1<< endl;
                    return false;
                }
                rowmap[i][num] = true;
                colmap[j][num] = true;
                seqmap[k][num] = true;
            }
        }

        return true;
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
    cout << s.isValidSudoku(matrix) << endl;


  return 0;
}
