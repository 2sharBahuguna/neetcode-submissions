class Solution {
private:
    int solve(int index,vector<int>& coins,int target,vector<vector<int>>& dp){
        if(index==0){
            if(target%coins[index]==0) return target/coins[index];
            return INT_MAX;
        }

        if(dp[index][target]!=-1) return dp[index][target];

        int not_take=solve(index-1,coins,target,dp);
        int take=INT_MAX;
        if(coins[index]<=target){
            int result=solve(index,coins,target-coins[index],dp);
            if(result!=INT_MAX) take=1+result;
        }

        return dp[index][target]=min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1,coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
