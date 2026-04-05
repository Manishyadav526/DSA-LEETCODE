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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;       //edge case
        queue<TreeNode*>qt;
        qt.push(root);
        while(!qt.empty()){
            int size=qt.size();
            //int i=0; for left side view
            //int n=size;
            while(size--){
            TreeNode* temp=qt.front();
            qt.pop();
            //i++;
            if(size==0){
            ans.push_back(temp->val); //it push only last node of each level
            }
            if(temp->left){
                qt.push(temp->left);
            }
            if(temp->right){
                qt.push(temp->right);
            }
            }
        }
        return ans;
    }
};
