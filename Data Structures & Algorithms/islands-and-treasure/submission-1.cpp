class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]==0)
                {
                    q.push({row,col});
                }
            }
        }

        int delr[]={-1,0,+1,0};
        int delc[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newR=r+delr[i];
                int newC=c+delc[i];

                if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]==INT_MAX)
                {
                    grid[newR][newC]=grid[r][c]+1;
                    q.push({newR,newC});
                }
            }
        }
    }
};
