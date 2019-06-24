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
    void solve(vector<TreeNode*> nodes) {
        vector<int> nums;
        vector<TreeNode*> next;
        if (nodes.size() == 0)
            return;
        for (auto node : nodes) {
            nums.push_back(node->val);
            if (node->left != NULL)
                next.push_back(node->left);
            if (node->right != NULL)
                next.push_back(node->right);
        }
        ret.push_back(nums);
        solve(next);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        solve({root});
        return ret;
    }
};

int main() {
    Solution s;


  return 0;
}
