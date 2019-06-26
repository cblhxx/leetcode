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

    void solve(TreeNode *root, int depth)
    {
        if(root == NULL) return;
        if(ret.size() == depth)
            ret.push_back(vector<int>());

        if (depth % 2 == 0)
            ret[depth].push_back(root->val);
        else
            ret[depth].insert(ret[depth].begin(), root->val);
        solve(root->left, depth + 1);
        solve(root->right, depth + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        solve(root, 0);
        return ret;
    }
};

int main() {
    Solution s;


  return 0;
}
