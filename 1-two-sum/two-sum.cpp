class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            int rem=target-nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==rem){
                    return {i ,j};
                }
            }
        }
        return {};
    }
};