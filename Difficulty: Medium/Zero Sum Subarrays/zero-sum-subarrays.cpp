class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        int count=0;
        int prefix_sum=0;
        mpp[0]=1;

        for(int i=0;i<n;i++){
            prefix_sum=prefix_sum+arr[i];
            if(mpp.count(prefix_sum)){
                count=count+mpp[prefix_sum];
                mpp[prefix_sum]++;
            }
            else{
                mpp[prefix_sum]++;
            }
        }
        return count;
    }
};