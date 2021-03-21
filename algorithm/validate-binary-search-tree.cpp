/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBoundBST(TreeNode* node, long min, long max) {
        if (!node) return true;
        if (node->val <= min || node->val >= max) return false;
        return isValidBoundBST(node->left, min, node->val)
            && isValidBoundBST(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return isValidBoundBST(root->left, std::numeric_limits<long>::min(), root->val)
            && isValidBoundBST(root->right, root->val, std::numeric_limits<long>::max());
    }
};
