class Solution {
private:
    int solve(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0; // No houses to rob
        if (n == 1) return arr[0]; // Only one house to rob
        
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Only one house to rob
        
        // Exclude the first house or the last house
        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end() - 1);

        return max(solve(numsA), solve(numsB));
    }
};
