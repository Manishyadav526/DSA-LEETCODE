/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void CountLeaf(Node*root ,int  &count){
    if(root==NULL){
        return;
    }
    if(!root->left && !root->right){
        count++;
    }
    
    CountLeaf(root->left , count);
    CountLeaf(root->right , count);
}
// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        int count=0;
        CountLeaf(root , count);
        return count;
    }
};