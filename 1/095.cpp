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
    vector<TreeNode*> solve(int start, int end) {
        if (start > end)
            return {NULL};

        vector<TreeNode*> ret;
        for (int i = start; i <= end; i++) {
            auto lefts = solve(start, i-1);
            auto rights = solve(i+1, end);

            for (auto left: lefts) {
                for (auto right: rights) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ret.push_back(root);
                }
            }
        }
        return ret;

    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if (n == 0)
            return {};
        return solve(1, n);
    }
};

int main() {
    Solution s;


  return 0;
}
