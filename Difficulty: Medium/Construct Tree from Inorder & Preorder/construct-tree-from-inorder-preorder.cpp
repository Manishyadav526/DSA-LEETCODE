/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/


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
                vector<int> &preorder,
                int inStart,
                int inEnd,
                int &Index,
                unordered_map<int,int> &mp) {
        
        if(inStart > inEnd)
            return NULL;
        
        // Create root from current postIndex
        Node* root = new Node(preorder[Index++]);
        
        // Find position in inorder
        int pos = mp[root->data];
        
        root->left = solve(inorder, preorder,
                           inStart, pos - 1,
                           Index, mp);
                           
        root->right = solve(inorder, preorder,
                            pos + 1, inEnd,
                            Index, mp);                   
        
        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        
        int n = inorder.size();
        int Index =0;
        
        unordered_map<int,int> mp;
        
        // Store inorder value → index
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        return solve(inorder, preorder, 0, n - 1, Index, mp);
    }
};
