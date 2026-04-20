class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        int N = numCourses;

        // ✅ adjacency list
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);

        for(auto &p : prerequisites){
            int u = p[0], v = p[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // ✅ reachability matrix
        vector<vector<bool>> reach(N, vector<bool>(N, false));

        // ✅ Kahn's Algorithm (Topo Sort)
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto neigh : adj[node]){

                // direct edge
                reach[node][neigh] = true;

                // propagate: whoever can reach 'node' can also reach 'neigh'
                for(int i = 0; i < N; i++){
                    if(reach[i][node]){
                        reach[i][neigh] = true;
                    }
                }

                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        // ✅ answer queries
        vector<bool> ans;
        for(auto &q : queries){
            int u = q[0], v = q[1];
            ans.push_back(reach[u][v]);
        }

        return ans;
    }
};