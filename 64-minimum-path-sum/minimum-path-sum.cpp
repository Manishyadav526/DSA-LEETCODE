class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m+1);
        for(int i=1;i<=m;i++) dp[i] = dp[i-1]+grid[0][i-1];
        dp[0] = INT_MAX;
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<=m;j++){
                dp[j] = min(dp[j], dp[j-1]) + grid[i-1][j-1];
            }
        }
        return dp[m];
    }
};