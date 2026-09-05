class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& visited)
    {
        visited[row][col]=true;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int newR=row+drow[i];
            int newC=col+dcol[i];

            if(newR>=0 && newC>=0 && newR<grid.size() && newC<grid[0].size() && grid[newR][newC]=='1' && !visited[newR][newC])
            {
                dfs(newR,newC,grid,visited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    dfs(i,j,grid,visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
