struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return 0;
        // shortcuts
        if (root->val == low) return root->val + rangeSumBST(root->right, low, high);
        if (root->val == high) return root->val + rangeSumBST(root->left, low, high);

        int sum = (low < root->val && root->val < high) ? root->val : 0;
        // should we go left?
        if (root->left && low < root->val) {
            sum += rangeSumBST(root->left, low, high);
        }
        // should we go right?
        if (root->right && root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }
        return sum;
    }
};
