class Solution {
private:
    void solve(int m, int n, vector<vector<int>>& dp) {
        // Initialize the starting point
        dp[0][0] = 1;

        // Fill the DP table
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue; // Skip the start point

                int down = (i > 0) ? dp[i-1][j] : 0; // Moving down (from above)
                int right = (j > 0) ? dp[i][j-1] : 0; // Moving right (from left)

                dp[i][j] = down + right; // Sum of ways to reach from above and from left
            }
        }
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        solve(m, n, dp);
        return dp[m-1][n-1]; // Return the number of unique paths to bottom-right corner
    }
};
