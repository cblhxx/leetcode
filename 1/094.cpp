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
    void solve(TreeNode *node, vector<int> &ret) {
        if (node == NULL)
            return;
        solve(node->left, ret);
        ret.push_back(node->val);
        solve(node->right, ret);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        //solve(root, ret);
        vector<TreeNode*> stack;

        TreeNode *n = root;
        while (n != NULL || stack.size() > 0) {
            if (n == NULL) {
                n = stack.back();
                n->left = NULL;
                stack.pop_back();
            }

            if (n->left != NULL) {
                stack.push_back(n);
                n = n->left;
                continue;
            }
            ret.push_back(n->val);
            if (n->right != NULL) {
                n = n->right;
                continue;
            }
            if (n->left == NULL && n->right == NULL)
                n = NULL;
        }
        return ret;
    }
};


int main() {
    Solution s;
    TreeNode nodes[3] {1,2,3};
    nodes[0].right = &nodes[2];
    nodes[0].left = &nodes[1];

    auto ret = s.inorderTraversal(&nodes[0]);
    for (auto n : ret)
        cout << n << " ";
    cout << endl;


  return 0;
}
