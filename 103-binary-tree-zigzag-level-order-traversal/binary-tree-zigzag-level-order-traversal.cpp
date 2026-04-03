class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> qt;
        qt.push(root);

        bool leftToRight = true;

        while(!qt.empty()){

            int size = qt.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++){

                TreeNode* cur = qt.front();
                qt.pop();

                int index;

                if(leftToRight)
                    index = i;
                else
                    index = size - 1 - i;

                level[index] = cur->val;

                if(cur->left) qt.push(cur->left);
                if(cur->right) qt.push(cur->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};