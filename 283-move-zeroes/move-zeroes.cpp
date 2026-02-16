class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int index=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[index]=nums[i];
                index++;
            }
        }
        for(int i=n-count;i<n;i++){
            nums[i]=0;
        }
    }
};