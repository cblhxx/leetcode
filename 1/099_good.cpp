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
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;

    void solve(TreeNode* root) {
        if (root == NULL)
            return;

        solve(root->left);
        if (prev != NULL && prev->val > root->val) {
            if (first == NULL)
                first = prev;
            second = root;
        }
        prev = root;
        solve(root->right);

    }
    void recoverTree(TreeNode* root) {
        first = second = prev = NULL;
        solve(root);
        if (first != NULL && second != NULL)
            swap(first->val, second->val);
    }
};

int main() {
    Solution s;


  return 0;
}
