class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        int end=0;
        int n =nums.size();
        int sum=0;
        int minSize=INT_MAX;
        while(end<n){
            sum=sum+nums[end];
            if(sum<target){
                end++;
            }
            else{
                while(sum>=target){
                minSize=min(minSize ,end-start+1);
                sum= sum- nums[start];
                start++;
            }
            end++;
        }
        }
        if(minSize==INT_MAX){
            return 0;
        }
        else{
            return minSize;
        }
    }
};