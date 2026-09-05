class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int& count)
    {
        vis[row][col]=1;
        count++;
        int n = grid.size();
        int m = grid[0].size();
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};

        for(int i=0;i<4;i++)
        {
            int newR=row+delrow[i];
            int newC=col+delcol[i];

            if(newR>=0 && newC>=0 && newR<n && newC<m && !vis[newR][newC] && grid[newR][newC]==1)
            {
                
                dfs(newR,newC,vis,grid,count);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int max_count=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                int count=0;
                if(grid[row][col]==1 && !vis[row][col])
                {
                    dfs(row,col,vis,grid,count);
                    max_count=max(max_count,count);
                }
            }
        }
        return max_count;
        
    }
};
