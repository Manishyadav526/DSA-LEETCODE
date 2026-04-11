class Solution {
  public:
      //helper func
      bool Detectcycle(int node ,vector<vector<int>>&adj , vector<bool>&path ,vector<bool>&visited){
         path[node]=1;
         visited[node]=1;
         
         for(int j=0;j<adj[node].size();j++){
             if(path[adj[node][j]]){  //if node occurss twice in same path //cycle detect
                 return 1;
             }
             if(visited[adj[node][j]]){
                 continue;                    //path already checked that no cycle
             }
            if(Detectcycle(adj[node][j], adj , path , visited)){
                return 1;
            } 
         }
         path[node]=0;
         return 0;
          
          
      }
      bool isCyclic(int V, vector<vector<int>> &edges) {
        //adj list creation
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
        if(!visited[i] && Detectcycle(i ,adj , path , visited)){
            return 1;
        }
        }
        return 0;
    }
};