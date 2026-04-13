/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * }; //preorder====root , left  ,right
 */
class Solution {
public:
    void Pre(TreeNode*root, vector<int>&ans){
    if(!root){
    return; 
    }
    ans.push_back(root->val);
    Pre(root->left , ans);
    Pre(root->right , ans);
  }

 vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    Pre(root , ans);
    return ans;
  }
};
        

