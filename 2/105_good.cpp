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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootInex = 0;
        return helper(preorder, rootInex, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int& rootIndex, vector<int>& inorder, int start, int end) {
        if(rootIndex >= preorder.size() || start > end) return nullptr;

        TreeNode* root = new TreeNode(preorder[rootIndex]);
        auto pos = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, preorder[rootIndex]));
        rootIndex ++;
        root->left  = helper(preorder, rootIndex, inorder, start, pos - 1);
        root->right = helper(preorder, rootIndex, inorder, pos + 1, end);
        return root;
    }
};

int main() {
    Solution s;


  return 0;
}
