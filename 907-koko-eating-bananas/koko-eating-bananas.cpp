class Solution {
public:
int funcmaxele(vector<int>& piles){
    int ans=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        ans=max(ans , piles[i]);
    }
    return ans;
}
long long func(vector<int>& piles, int mid){
    long long totalhour=0;
    for(int i=0;i<piles.size();i++){
    totalhour=totalhour+ceil(double(piles[i])/double(mid));
}
return totalhour;
};

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high= funcmaxele(piles);
        while(low<=high){
            int mid=(low+high)/2;
             long long totalhour=func(piles , mid);
             if(totalhour<=h){
                high=mid-1;
             }
             else{
                low=mid+1;
            }
        }
         return low;
        
    }
};