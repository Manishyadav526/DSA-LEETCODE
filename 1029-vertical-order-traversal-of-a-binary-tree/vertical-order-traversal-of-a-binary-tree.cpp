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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int col = front.second.first;
            int row = front.second.second;

            nodes.push_back({col, row, node->val});

            if(node->left) q.push({node->left, {col - 1, row + 1}});
            if(node->right) q.push({node->right, {col + 1, row + 1}});
        }

        sort(nodes.begin(), nodes.end(), [](auto &a, auto &b) {
            if(a[0] != b[0]) return a[0] < b[0];
            if(a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        });

        vector<vector<int>> result;
        int prevCol = INT_MIN;

        for(auto &v : nodes) {
            int col = v[0];
            int value = v[2];

            if(col != prevCol) {
                result.push_back({});
                prevCol = col;
            }
            result.back().push_back(value);
        }

        return result;
    }
};
