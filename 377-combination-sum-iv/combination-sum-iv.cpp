class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Use unsigned int to prevent overflow errors during LeetCode's intermediate test case checks
        vector<unsigned int> dp(target + 1, 0);
        
        // Base case: 1 way to reach target 0
        dp[0] = 1;
        
        // Build up the DP array from step 1 to the target
        for (int i = 1; i <= target; i++) {
            
            // Try every possible "jump size" from our given numbers
            for (int num : nums) {
                // If the jump is legal (doesn't go below ground)
                if (i - num >= 0) {
                    // Accumulate the combinations from the past step
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};