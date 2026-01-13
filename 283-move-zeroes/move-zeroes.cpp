class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int k=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            else{
                nums[k]=nums[i];
                k++;
            }
        }
        for(int i=n-count;i<n;i++){
            nums[i]=0;
        }
    }
};