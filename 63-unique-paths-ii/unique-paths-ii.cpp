class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if(obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i - 1 + (i == 0)][j] + dp[i][j - 1 + (j == 0)];
            }
        }
        return dp[n - 1][m - 1];
    }
};