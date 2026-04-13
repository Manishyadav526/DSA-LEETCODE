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
    bool checkpath(TreeNode* root , int targetSum , int &sum){
        if(!root){
            return 0;
        }
        sum=sum+root->val;

        if (!root->left && !root->right) {
        bool ok = (sum == targetSum);
        sum -= root->val;   // backtrack before return
        return ok;
        }
        bool left=checkpath(root->left, targetSum , sum);
        bool right=checkpath(root->right,targetSum, sum);
        
        sum=sum-root->val;
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        if(!root){
            return 0;
        }
        return checkpath(root , targetSum , sum); 
    }
};