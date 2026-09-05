class Solution {
private:
    int solve(int idx,vector<vector<int>>& dp,vector<int>& coins,int target){
        if(idx<0) return 0;
        if(target==0) return 1;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int not_take=solve(idx-1,dp,coins,target);
        int take= 0;
        if(coins[idx]<=target){
            take=solve(idx,dp,coins,target-coins[idx]);
        }
        return dp[idx][target]=take+not_take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,dp,coins,amount);
    }
};
