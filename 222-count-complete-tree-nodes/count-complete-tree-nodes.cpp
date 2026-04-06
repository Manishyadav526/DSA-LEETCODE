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
// class Solution {
// public:
//     void TotalNodes(TreeNode* root ,int &count){
//         if(root==NULL){
//             return;
//         }
//         count++;
//         TotalNodes(root->left , count);
//         TotalNodes(root->right ,count);
//     }
//     int countNodes(TreeNode* root) {
//         int count=0;
//         TotalNodes(root ,count);
//         return count;
        
//     }
// };

 class Solution {
 public:
  int countNodes(TreeNode* root) {
    if(!root){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
  }
};