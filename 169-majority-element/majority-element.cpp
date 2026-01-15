class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int countMajority = nums.size()/2;
        for(auto num : nums){
            int count = 0;
            for(auto element : nums){
                if(element == num){
                    count++;
                }
            }
            if(count > countMajority){
                return num;
            }
        }
        return 0;
    }
};
