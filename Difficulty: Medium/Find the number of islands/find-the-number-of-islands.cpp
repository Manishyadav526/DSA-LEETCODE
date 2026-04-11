class Solution {
  public:
  
    
    int row[8]={-1,1,0,0,-1,-1,1,1};
    int col[8]={0,0,-1,1,-1,1,-1,1};
    
    bool valid(int i , int j ,int r ,int c){
        if(i>=0&&i<r&&j>=0&&j<c){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<int>>Visited(r,vector<int>(c,0));  //2d vector initilaze 
        queue<pair<int,int>>q;
        int count=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!Visited[i][j]&&grid[i][j]=='L'){
                    count++;
                    q.push(make_pair(i,j));
                    Visited[i][j] = 1;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    
                    for(int k=0;k<8;k++){
                        if(valid(x+row[k],y+col[k] ,r ,c)&&grid[x+row[k]][y+col[k]]=='L'&&!Visited[x+row[k]][y+col[k]]){
                            Visited[x+row[k]][y+col[k]]=1;
                            q.push(make_pair(x+row[k],y+col[k]));
                        }
                    }
                }
            }
        }
        
    }
        return count;
    }
};