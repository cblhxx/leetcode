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
    vector<vector<int>> ret;
    void solve(TreeNode* node, int level) {
        if (node == NULL)
            return;
        if (level == ret.size())
            ret.push_back(vector<int>{});
        ret[level].push_back(node->val);
        solve(node->left, level+1);
        solve(node->right, level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        solve(root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution s;


  return 0;
}
