#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int solve(int start, int end, vector<vector<int>> &dp) {
        if (start >= end)
            return 1;

        if (dp[start][end] > 0)
            return dp[start][end];

        int ret = 0;
        for (int i = start; i <= end; i++) {
            auto lefts = solve(start, i-1, dp);
            auto rights = solve(i+1, end, dp);

            ret += (lefts * rights);
            //cout << start << " " << end << " " << i << " " << lefts << " " << rights << endl;
        }
        dp[start][end] = ret;
        return ret;

    }
    int numTrees(int n) {
        if (n == 0)
            return 0;
        vector<TreeNode*> ret;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return solve(1, n, dp);
    }
};

int main() {
    Solution s;
    cout << s.generateTrees(0) << endl;
    cout << s.generateTrees(1) << endl;
    cout << s.generateTrees(2) << endl;
    cout << s.generateTrees(3) << endl;
    cout << s.generateTrees(4) << endl;
    cout << s.generateTrees(19) << endl;


  return 0;
}
