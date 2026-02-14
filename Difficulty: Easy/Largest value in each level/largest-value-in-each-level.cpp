// User function Template for C++
void LevelOrder(Node*root ,vector<int>& maxi){
    
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    
    
    while(!q.empty()){
        
        int n=q.size();
        int maxx=INT_MIN;
        
        for(int i=0;i<n;i++){
        Node*temp=q.front();
        q.pop();
        
        maxx=max(maxx,temp->data); 
        
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
        maxi.push_back(maxx);
    }
    
}
class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        vector<int>maxi;
        LevelOrder(root , maxi);
        return maxi;
    }
};