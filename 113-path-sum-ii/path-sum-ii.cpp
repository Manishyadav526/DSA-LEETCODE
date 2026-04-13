class Solution {
public:

    void solve(TreeNode* root, int targetSum,
               vector<int>& path,
               vector<vector<int>>& ans,
               int sum) {

        if (!root) return;

        // include current node
        path.push_back(root->val);
        sum += root->val;

        // if leaf node
        if (!root->left && !root->right) {
            if (sum == targetSum) {
                ans.push_back(path);
            }
        } else {
            // go left and right
            solve(root->left, targetSum, path, ans, sum);
            solve(root->right, targetSum, path, ans, sum);
        }

        // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(root, targetSum, path, ans, 0);

        return ans;
    }
};