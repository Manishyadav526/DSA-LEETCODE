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
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> qt;
        qt.push(root);

        while (!qt.empty()) {
            int size = qt.size();

            ans.push_back(qt.back()->val);

            while (size--) {
                TreeNode* temp = qt.front();
                qt.pop();

                if (temp->left)  qt.push(temp->left);
                if (temp->right) qt.push(temp->right);
            }
        }

        return ans;
    }
};
