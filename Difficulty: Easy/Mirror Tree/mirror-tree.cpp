/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    void mirror(Node* root) {
        if (root == NULL) return;

        // swap left and right child
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // recursively mirror subtrees
        mirror(root->left);
        mirror(root->right);
    }
};
