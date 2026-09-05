class Solution {
private:
    int solve(int prev,int curr,vector<int>& nums,vector<vector<int>>& dp,int n){
        if(curr==nums.size()) return 0;

        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];

        int not_take= solve(prev,curr+1,nums,dp,n);
        int take=0;
        if(nums[prev]<nums[curr] || prev==-1){
            take= 1+solve(curr,curr+1,nums,dp,n);
        }

        return dp[curr][prev+1]= max(take,not_take);

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(-1,0,nums,dp,n);
    }
};
