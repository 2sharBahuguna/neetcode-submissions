class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==0){
                    q.push({row,col});
                }
            }
        }
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            
            q.pop();
            for(int i=0;i<4;i++){
                int newR=row+delR[i];
                int newC=col+delC[i];

                if(newR<n && newC<m && newR>=0 && newC>=0 && grid[newR][newC]==2147483647){
                    grid[newR][newC]=grid[row][col]+1;
                    q.push({newR,newC});
                }
            }
        }
    }
};
