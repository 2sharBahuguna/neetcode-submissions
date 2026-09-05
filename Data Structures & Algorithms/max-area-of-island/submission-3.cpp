class Solution {
private:
    void dfs(int row,int col,int& count,vector<vector<bool>>& visited,vector<vector<int>>& grid)
    {
        visited[row][col]=1;
        count+=1;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int newR=row+delRow[i];
            int newC=col+delCol[i];

            if(newR>=0 && newC>=0 && newR<grid.size() && newC<grid[0].size() && !visited[newR][newC] && grid[newR][newC]==1)
            {
                dfs(newR,newC,count,visited,grid);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int maxCount=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                int count=0;
                if(grid[row][col]==1 && !visited[row][col])
                {
                    dfs(row,col,count,visited,grid);
                    maxCount=max(maxCount,count);
                }
            }
        }
        return maxCount;
    }
};
