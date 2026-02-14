/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
 void SumOfBT(Node*root ,int &sum){
     if(root==NULL){
         return;
     }
     sum=sum+root->data;
     SumOfBT(root->left , sum);
     SumOfBT(root->right , sum);
     
 }
// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        int sum=0;
        SumOfBT(root , sum);
        return sum;
    }
};