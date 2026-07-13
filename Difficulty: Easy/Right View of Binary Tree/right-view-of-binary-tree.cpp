/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int>ans;
         if(root==NULL){
             return ans;
         }
         queue<Node*>qt;
         qt.push(root);
         while(!qt.empty()){
             int n=qt.size();
             int i=0;
             while(n--){
                Node*temp=qt.front();
                qt.pop();
                if(n==0){
                    ans.push_back(temp->data);
                }
                //i++;
                if(temp->left){
                    qt.push(temp->left);
                } 
                if(temp->right){
                    qt.push(temp->right);
                } 
            }
        }
        return ans;
    }
};