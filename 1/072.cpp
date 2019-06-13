#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int _solve(string& word1, string& word2, int n1, int n2, vector<vector<int>> &dp) {
        if (dp[n1][n2] != -1) {
            return dp[n1][n2];
        }

        if (n1 == 0 || n2 == 0) {
            dp[n1][n2] = max(n1, n2);
        }
        else if (word1[n1-1] == word2[n2-1]) {
            dp[n1][n2] = _solve(word1, word2, n1-1, n2-1, dp);
        }
        else {
            int mdist = std::min(_solve(word1, word2, n1, n2-1, dp), _solve(word1, word2, n1-1, n2, dp));
            mdist = std::min(mdist, _solve(word1, word2, n1-1, n2-1, dp));
            dp[n1][n2] = mdist + 1;
        }

        //cout << n1 << " " << n2 << " " << dp[n1][n2] << endl;
        return dp[n1][n2];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));

        int md = _solve(word1, word2, word1.size(), word2.size(), dp);
        /*
        for (auto l : dp) {
            for (auto n : l) {
                cout << n << " ";
            }
            cout <<endl;
        }
        */
        return md;
    }
};

int main() {
    Solution s;
    cout << s.minDistance("a", "b") << endl;
    cout << s.minDistance("horse", "ros") << endl;
    cout << s.minDistance("intention", "execution") << endl;


  return 0;
}
