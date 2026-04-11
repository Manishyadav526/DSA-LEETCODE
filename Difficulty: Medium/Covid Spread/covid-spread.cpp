// User function Template for C++

class Solution {
  public:
  
   //setting all moving direction in the arrays
   int row[4]={-1,1,0,0};
   int col[4]={0,0,-1,1};
   
   //valid func to avoid segmentation fault
   bool valid(int i ,int j , int r , int c){
       if(i>=0&&i<r&&j>=0&&j<c){
           return true;
       }
       else{
           return false;
       }
   }
   
    int helpaterp(vector<vector<int>> hospital) {
        // code here
        int r=hospital.size();        //row size
        int c=hospital[0].size();     //col size
        
        queue<pair<int , int>>q;       //push row , col in queue
        
        //push every infected person in queue
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }
        
        //set timer to zero 
        int timer=0;
        
        //doing bfs
        while(!q.empty()){
            int curr_patient=q.size();
            bool spread = false;  //add for removing error******
            
            while(curr_patient--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
            //checking all possible directions
            for(int k=0;k<4;k++){
                if(valid(i+row[k],j+col[k],r,c) && hospital[i+row[k]][j+col[k]]==1){
                    hospital[i+row[k]][j+col[k]]=2;
                    q.push(make_pair(i+row[k],j+col[k]));
                    spread = true; //////********
                }
            }
            }
            if(spread) timer++; // /////*******
        }
        
        //check if any patient left without covid or not
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==1){
                    return -1;
                }
            }
        }
        return timer;
    }
};
