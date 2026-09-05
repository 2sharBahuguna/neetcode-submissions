class Solution {
private:
    int solve(int index,int target,vector<vector<int>>& dp,vector<int>& arr)
    {
        if(index<0) return 0;

        if(target==0) return 1;

        if(dp[index][target]!=-1) return dp[index][target];

        int not_take=0+solve(index-1,target,dp,arr);
        int take=0;
        if(arr[index]<=target)
        {
            take=solve(index,target-arr[index],dp,arr);
        }

        return dp[index][target]=take + not_take;
        
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,dp,coins);
    }
};
