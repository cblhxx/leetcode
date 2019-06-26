#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootInex = postorder.size() - 1;
        return helper(postorder, rootInex, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& postorder, int& rootIndex, vector<int>& inorder, int start, int end) {
        //cout << rootIndex << " "  << start << " " << end << endl;
        if(rootIndex < 0 || start > end) return nullptr;

        TreeNode* root = new TreeNode(postorder[rootIndex]);
        auto pos = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, postorder[rootIndex]));
        rootIndex--;
        root->right = helper(postorder, rootIndex, inorder, pos + 1, end);
        root->left = helper(postorder, rootIndex, inorder, start, pos - 1);
        return root;
    }
};

int main() {
    Solution s;


  return 0;
}
