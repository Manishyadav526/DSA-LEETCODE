/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/


class Solution {
public:
    vector<int> rightView(Node *root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node*temp=q.front();
                if(n==0){
                ans.push_back(temp->data);
                }
                q.pop();
                if(temp->left){
                   q.push(temp->left); 
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
        }
        return ans;
    }
};