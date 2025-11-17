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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>>ans;
        if (root == nullptr) return ans;
        queue<TreeNode*>qt;
        
        qt.push(root);
        
        while(!qt.empty()){
            vector<int>level;
            int size=qt.size();
            while(size--){
                TreeNode*temp=qt.front();
                qt.pop();
                level.push_back(temp->val);
                
            if(temp->left){
            qt.push(temp->left);
        }
            if(temp->right){
            qt.push(temp->right);
        }
            }
         ans.push_back(level);
        }
        return ans;
    }
};