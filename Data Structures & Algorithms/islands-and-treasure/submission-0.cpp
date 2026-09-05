class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]==0) //start from 0 and +1 as we find INT_MAX in other indexes
                {
                    q.push({row,col});
                }
            }
        }

        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int newR = r+delrow[i];
                int newC= c+delcol[i];

                if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]==INT_MAX)
                {
                    grid[newR][newC]=grid[r][c]+1; //updates the position to +1 depedning on how much its closer to 0
                    q.push({newR,newC});
                }
            }        
        }
    }
};
