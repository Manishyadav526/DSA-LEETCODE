class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //edge case
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int number=nums[0];
        int curr_len=1;
        int max_len=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==number){
                continue;
            }
            else if(nums[i]==number+1){
                curr_len++;
                max_len=max(curr_len,max_len);
                //number=nums[i];
            }
            else{
                curr_len=1;
                //number=nums[i];
            }
            number=nums[i];
        }
        return max_len;
        
    }
};