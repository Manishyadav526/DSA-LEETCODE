/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
void CountNonLeaf(Node*root ,int  &count){
    if(root==NULL){
        return;
    }
    if(root->left || root->right){
        count++;
    }
    
    CountNonLeaf(root->left , count);
    CountNonLeaf(root->right , count);
}
class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // Code here
        int count=0;
        CountNonLeaf(root , count);
        return count;
    }
};