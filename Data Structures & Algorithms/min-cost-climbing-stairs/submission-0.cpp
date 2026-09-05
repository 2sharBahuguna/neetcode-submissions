class Solution {
private:
    int solve(int index,vector<int>& dp,vector<int>& arr)
    {
        if(index<0) return 0;

        if(dp[index]!=-1) return dp[index];

        int left=arr[index]+solve(index-1,dp,arr);
        int right=arr[index]+solve(index-2,dp,arr);

        return dp[index]=min(left,right);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(n-1,dp,cost),solve(n-2,dp,cost));
    }
};
