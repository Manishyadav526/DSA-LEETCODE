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
  
  void LView(Node*root , int level , vector<int>&ans){
      if(root==NULL){
          return;
  }
  if(level==ans.size()){
      ans.push_back(root->data);
  }
  LView(root->left , level+1 , ans);
  LView(root->right , level+1 , ans);
  
  }
    vector<int> leftView(Node *root) {
        //  code here
        int level=0;
        vector<int>ans;
        LView(root , level , ans);
        return ans;
        
    }
};
