class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int max=candyType.size();
        int unique=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<max;i++){
            if(mpp.find(candyType[i])==mpp.end()){
                mpp[candyType[i]]++;
                unique++;
            }
            else{
                mpp[candyType[i]]++; 
            }
        }
        int eat=max/2;
        if(eat>unique){
            return unique;
        }
        
        return eat;   
    }
};