class Solution {
public:

    bool checkpath(TreeNode* root, int targetSum, int sum) {
        if (!root) return false;

        sum += root->val;

        if (!root->left && !root->right) {
            return sum == targetSum;
        }

        return checkpath(root->left, targetSum, sum) ||
               checkpath(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkpath(root, targetSum, 0);
    }
};