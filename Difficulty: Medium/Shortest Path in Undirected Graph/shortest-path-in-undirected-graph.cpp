class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        
        // adjacency list
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected
        }
        
        // distance array
        vector<int> dist(V, INT_MAX);
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int j = 0; j < adj[node].size(); j++){
                int neigh = adj[node][j];
                
                if(dist[node] + 1 < dist[neigh]){
                    dist[neigh] = dist[node] + 1;
                    q.push(neigh);
                }
            }
        }
        
        // unreachable nodes → -1
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
