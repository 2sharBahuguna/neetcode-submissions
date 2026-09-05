class Solution {
private:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid,int n, int m)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[] = {-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newR=r+delrow[i];
                int newC=c+delcol[i];

                if(newR>=0 && newC>=0 && newR<n && newC<m && vis[newR][newC]==0 && grid[newR][newC]=='1')
                {
                    vis[newR][newC]=1;
                    q.push({newR,newC});
                }
            }
        }
    }
        
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++)
        {
            for(int col =0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    count++;
                    bfs(row,col,vis,grid,n,m);
                }
            }
        }
        return count;
    }
};
