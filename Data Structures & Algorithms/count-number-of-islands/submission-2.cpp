class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;

        int delr[]={-1,0,+1,0};
        int delc[]={0,+1,0,-1};

        for(int i=0;i<4;i++)
        {
            int r=row+delr[i];
            int c=col+delc[i];

            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]=='1' && !vis[r][c])
            {
                dfs(r,c,vis,grid);
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]=='1' && !vis[row][col])
                {
                    dfs(row,col,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
