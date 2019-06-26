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
    TreeNode* solve(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = solve(nums, left, mid-1);
        node->right = solve(nums, mid+1, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};

int main() {
    Solution s;


  return 0;
}
