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
    vector<int> leftView(Node *root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*temp=q.front();
            int n=q.size();
            ans.push_back(temp->data);
            while(n--){
                Node*temp=q.front();
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
