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
Node* insertele(Node* root, int key){
    if(!root){
        Node*temp=new Node(key);
        return temp;
    }
    if(key<root->data){
        root->left=insertele(root->left,key);
    }
    else{
        root->right=insertele(root->right, key);
    }
    return root;
}

class Solution {
  public:
    Node* insert(Node* root, int key) {
        root=insertele(root , key);
        return root;
    }
};