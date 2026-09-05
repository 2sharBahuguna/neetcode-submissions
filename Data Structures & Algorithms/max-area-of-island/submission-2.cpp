class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int& count)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        count++;
        int delr[]={-1,0,+1,0};
        int delc[]={0,+1,0,-1};

        for(int i=0;i<4;i++)
        {
            int newR=r+delr[i];
            int newC=c+delc[i];

            if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]==1 && !vis[newR][newC])
            {
                dfs(newR,newC,grid,vis,count);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int maxCount=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                int count=0;
                if(grid[row][col]==1 && !vis[row][col])
                {
                    dfs(row,col,grid,vis,count);
                    maxCount=max(maxCount,count);
                }
            }
        }
        return maxCount;
    }

};
