class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        auto bfs = [&](int src) {
            queue<int> q;
            q.push(src);
            color[src] = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto nei : graph[node]){
                    if(color[nei] == -1){
                        color[nei] = 1 - color[node];
                        q.push(nei);
                    }
                    else if(color[nei] == color[node]){
                        return false;
                    }
                }
            }
            return true;
        };

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!bfs(i)) return false;
            }
        }

        return true;
    }
};