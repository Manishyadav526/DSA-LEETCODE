/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

int height(Node* root, bool &valid) {
    if (!root || !valid) {
        return 0;
    }

    int l = height(root->left, valid);
    int r = height(root->right, valid);

    if (abs(l - r) > 1) {
        valid = 0;
    }

    return 1 + max(l, r);
}
class Solution {
public:

    bool isBalanced(Node* root) {
    bool valid = 1;
    height(root, valid);
    return valid;  
    }
    
};

