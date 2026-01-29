class Solution {
public:
    int maxi(vector<int>& nums){
        int m = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            m = max(m,nums[i]);
        }
        return m;
    }

    long long SumofD(vector<int>& nums,int mid){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil(double(nums[i])/double(mid));
        }
        return sum;
    };
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; 
        int high = maxi(nums);
        while(low<=high){
            int mid = low+(high-low)/2;
            if(SumofD(nums , mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};