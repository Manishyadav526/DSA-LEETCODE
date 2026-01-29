class Solution {
public:
    int maxi(vector<int>& nums){
        int m = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            m = max(m,nums[i]);
        }
        return m;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int m = maxi(nums);
        int low = 1, high = m,mid;
        while(low<=high){
            int sum = 0;
            mid = (low+high)/2;
            for(int i =0;i<nums.size();i++){
                sum = sum + ((nums[i]+mid-1)/mid);
            }
            if(sum<=threshold) {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};