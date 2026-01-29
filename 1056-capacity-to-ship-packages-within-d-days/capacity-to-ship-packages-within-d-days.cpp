class Solution {
public:
    int funcmax(vector<int>& weights){
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi , weights[i]);
        }
        return maxi;
    };
    int fsum(vector<int>& weights){
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        return sum;
    };


    int func(vector<int>& weights ,int mid ){
        int days=1;
        int load=0;

        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                days=days+1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int low= funcmax(weights);
        int high=fsum(weights);
        while(low<=high){
            int mid=low+(high-low)/2;
            int NoOfDays=func(weights ,mid);

            if( NoOfDays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;   
    }
};