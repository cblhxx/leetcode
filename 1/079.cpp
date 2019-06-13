#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>>& board, vector<vector<int>> &map, string word, int y, int x, int l) {
        if (l == word.length())
            return true;
        if (map[y][x] == 1)
            return false;
        if (word[l] != board[y-1][x-1])
            return false;
        map[y][x] = 1;

        //cout << x << " " << y << " " << l << endl;
        bool ret = solve(board, map, word, y + 1, x, l + 1) ||
                   solve(board, map, word, y, x + 1, l + 1) ||
                   solve(board, map, word, y - 1, x, l + 1) ||
                   solve(board, map, word, y, x - 1, l + 1);
        map[y][x] = 0;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0)
            return false;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> map(n + 2, vector<int>(m + 2, 0));

        for (int i = 1; i <= n; i++) {
            map[i][0] = 1;
            map[i][m+1] = 1;
        }
        for (int i = 1; i <= m; i++) {
            map[0][i] = 1;
            map[n+1][i] = 1;
        }

        /*
        for (auto line : map) {
            for (auto num : line)
                cout << num << " ";
            cout << endl;
        }
        */

        //return (solve(board, map, word, 1, 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                //cout << "begin " << i << " " << j << endl;
                if (solve(board, map, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    cout << s.exist(board, "AB") << endl;
    cout << s.exist(board, "AS") << endl;
    cout << s.exist(board, "ABCCED") << endl;
    cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;


  return 0;
}
