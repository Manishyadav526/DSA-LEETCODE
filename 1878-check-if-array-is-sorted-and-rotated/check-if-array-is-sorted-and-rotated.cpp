class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                continue;
            }
            else{
                count++;
            }
        }
        if(count>0){ //for checking the first and last element (if the complete array is not sorted)
            if(nums[n-1]>nums[0]){
            count++;
        }
        }
        return (count<=1)? true: false;
    }
};