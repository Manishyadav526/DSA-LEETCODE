/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:

    Node* solve(vector<int> &inorder,
                vector<int> &postorder,
                int inStart,
                int inEnd,
                int &postIndex,
                unordered_map<int,int> &mp) {
        
        if(inStart > inEnd)
            return NULL;
        
        // Create root from current postIndex
        Node* root = new Node(postorder[postIndex--]);
        
        // Find position in inorder
        int pos = mp[root->data];
        
        // IMPORTANT: build right subtree first
        root->right = solve(inorder, postorder,
                            pos + 1, inEnd,
                            postIndex, mp);
        
        root->left = solve(inorder, postorder,
                           inStart, pos - 1,
                           postIndex, mp);
        
        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        
        int n = inorder.size();
        int postIndex = n - 1;
        
        unordered_map<int,int> mp;
        
        // Store inorder value → index
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        return solve(inorder, postorder, 0, n - 1, postIndex, mp);
    }
};
