class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ele=1;
        for(int i=1;i<n;i++){
                if(nums[i]!=nums[i-1]){
                    nums[ele]=nums[i];
                    ele++;
                }
                else{
                    continue;
                }
            }
            return ele;
    }
};