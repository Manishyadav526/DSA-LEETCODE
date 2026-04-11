class Solution {
public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        vector<int> adj[V];
        
        // create adjacency list
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int>q;
        vector<int>colour(V,-1);
        q.push(0);
        colour[0]=0;   //colour    //0=red  , 1=blue
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                if(colour[adj[node][j]]!=-1){ //if already coloured
                    if(colour[adj[node][j]]==colour[node]){
                        return false;
                    }
                    else{
                        continue;
                    }
                }
                //if not coloured
                 if(colour[adj[node][j]]==-1){
                     colour[adj[node][j]]=(colour[node]+1)%2;
                     q.push(adj[node][j]);
                    }
            }
        }   
        return true;
        
    }
};