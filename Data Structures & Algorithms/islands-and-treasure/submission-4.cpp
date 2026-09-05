class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
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
                int newR= row+delR[i];
                int newC= col+delC[i];

                if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]==2147483647){
                    grid[newR][newC]=1+grid[row][col];
                    q.push({newR,newC});
                }
            }
        }

    }
};
