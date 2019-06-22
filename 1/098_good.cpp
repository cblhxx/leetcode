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
    bool solve(TreeNode* node, TreeNode* &prev) {
        if (node == NULL)
            return true;

        if (!solve(node->left, prev))
            return false;
        if (prev != NULL && prev->val >= node->val)
            return false;
        return solve(node->right, node);
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;

        TreeNode* prev = NULL;
        return solve(root, prev);
    }
};

int main() {
    Solution s;


  return 0;
}
