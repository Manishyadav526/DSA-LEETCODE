class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        vector<int>result;
        for(int i=0;i<n;i++){
            int idx=nums[i]-1;
            ans[idx]=1;
        }
        for(int i=0;i<n;i++){
            if(ans[i]!=1){
                result.push_back(i+1);
            }
        }
        return result;
    }
};