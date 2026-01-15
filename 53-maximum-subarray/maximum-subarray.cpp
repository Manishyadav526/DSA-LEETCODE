class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();


         int maxi = nums[0];      // stores the maximum sum found so far
        int currentSum = nums[0]; // stores the sum of the current subarray


        for(int i=1;i<n;i++){
            // Either extend the current subarray OR start new from nums[i]
            currentSum = max(nums[i], currentSum + nums[i]);

            // Update the maximum sum if needed
            maxi = max(maxi, currentSum);
        } 
        return maxi;
    }
};