/*
class Node {
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

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root){
            return false;
        }
        if(root->data==key){
            return true;
        }
        if(key<root->data){
            search(root->left, key);
        }
        else{
            search(root->right, key);
        }
    }
};