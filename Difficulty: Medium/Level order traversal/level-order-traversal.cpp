/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        if (root == nullptr) return ans;
        queue<Node*>qt;
        
        qt.push(root);
        
        while(!qt.empty()){
            vector<int>level;
            int size=qt.size();
            while(size--){
                Node*temp=qt.front();
                qt.pop();
                level.push_back(temp->data);
                
            if(temp->left){
            qt.push(temp->left);
        }
            if(temp->right){
            qt.push(temp->right);
        }
            }
         ans.push_back(level);
        }
        return ans;
    }
};