class Solution {
private:
    void dfs(int x, int y, int num, vector<vector<int>>& v, vector<vector<int>>& heights) {
        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || heights[x][y] < num || v[x][y]) {
            return;
        }
        v[x][y] = 1;
        dfs(x - 1, y, heights[x][y], v, heights);
        dfs(x, y - 1, heights[x][y], v, heights);
        dfs(x + 1, y, heights[x][y], v, heights);
        dfs(x, y + 1, heights[x][y], v, heights);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }
        
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> v1(m, vector<int>(n, 0));
        vector<vector<int>> v2(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights[i][0], v1, heights);  // Pacific border
            dfs(i, n - 1, heights[i][n - 1], v2, heights);  // Atlantic border
        }

        for (int i = 0; i < n; i++) {
            dfs(0, i, heights[0][i], v1, heights);  // Pacific border
            dfs(m - 1, i, heights[m - 1][i], v2, heights);  // Atlantic border
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v1[i][j] && v2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
