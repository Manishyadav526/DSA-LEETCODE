/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* delNode(Node* root, int x) {
        if (root == NULL) return root;

        if (x < root->data) {
            root->left = delNode(root->left, x);
        }
        else if (x > root->data) {
            root->right = delNode(root->right, x);
        }
        else {
            if (root->left == NULL) {
                return root->right;
            }
            else if (root->right == NULL) {
                return root->left;
            }
            Node* curr = root->right;
            while (curr->left != NULL) {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = delNode(root->right, curr->data);
        }

        return root;
    }
};
