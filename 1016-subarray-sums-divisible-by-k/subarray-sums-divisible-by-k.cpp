class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        int prefixSum=0;
        int rem ,total=0;
        for(int i=0;i<n;i++){
            prefixSum=prefixSum+nums[i];
            rem=prefixSum % k;

            if(rem<0){
                rem=k+rem; // if our rem is negative make it positive
            }
            if(m.count(rem)){
                total=total+m[rem];
                m[rem]++;
            }
            else{
                m[rem]=1;
            }
        }
        return total;

        
    }
};