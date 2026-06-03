class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        if(nums.size()<3){
            return nums[n];
        }
        unordered_map<int,int>mpp;
        int count=0;
        for(int i=n;i>=0;i--){
            if(mpp.find(nums[i])==mpp.end()){
                if(count==2){
                    return nums[i];
                }
                mpp[nums[i]]++;
                count++;

            }
            else{
                continue;
            }
        } 
        return nums[n];
    }
};