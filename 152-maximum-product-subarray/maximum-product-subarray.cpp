class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxMultiply=nums[0];
        for(int i=0;i<n;i++){
             int currentMultiply=1;

            for(int j=i;j<n;j++){

                currentMultiply=currentMultiply*nums[j];
                maxMultiply=max(currentMultiply , maxMultiply);
            }
        } 

        return maxMultiply;
    }
};