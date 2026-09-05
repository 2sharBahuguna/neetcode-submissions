class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& heights,int num,vector<vector<int>>& vis)
    {
        if(row<0 || col <0 || row>=heights.size() || col>=heights[0].size() || vis[row][col] || heights[row][col]<num)
        {
            return;
        }

        vis[row][col]=1;

        dfs(row-1,col,heights,heights[row][col],vis);
        dfs(row+1,col,heights,heights[row][col],vis);
        dfs(row,col-1,heights,heights[row][col],vis);
        dfs(row,col+1,heights,heights[row][col],vis);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> v1(n,vector<int>(m,0));
        vector<vector<int>> v2(n,vector<int>(m,0));

        for(int i = 0; i < m; i++) {
            dfs(0, i, heights, heights[0][i], v1);
            dfs(n - 1, i, heights, heights[n - 1][i], v2);
        }

        for(int i = 0; i < n; i++) {
            dfs(i, 0, heights, heights[i][0], v1);
            dfs(i, m - 1, heights, heights[i][m - 1], v2);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v1[i][j] && v2[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};
