class Solution {
private:
    int solve(int index,vector<int>& arr,int k,vector<vector<int>>& dp)
    {
        if(index==0)
        {
            if(k%arr[0]==0)
            {
                return k/arr[0];
            }
            else
            {
                return INT_MAX;
            }
        }
        if(dp[index][k]!=-1) return dp[index][k];
        int not_take=0+ solve(index-1,arr,k,dp);
        int take=INT_MAX;
        if(arr[index]<=k)
        {
            int result=solve(index,arr,k-arr[index],dp);
            if(result!=INT_MAX) take=1+result;
        }
        
        return dp[index][k]=min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
