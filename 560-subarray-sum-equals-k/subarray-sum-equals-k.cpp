class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int totalSum=0;
        int prefixSum=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            prefixSum=prefixSum+nums[i];
            if(mpp.count(prefixSum - k)){
                totalSum=totalSum+ mpp[prefixSum - k];
                mpp[prefixSum]++;
                

            }
            else{
                mpp[prefixSum]++;
            }

        }
        return totalSum;  
    }
};