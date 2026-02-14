/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
 void Total(Node *node , int &count){
     if(node==NULL){
         return;
     }
     count++;
     Total(node->left,count);
     Total(node->right,count);
 }

class Solution {
  public:
    int getSize(Node* node) {
        // code here
     int count=0;
     Total(node , count);
     return count;
    }
};