class Solution {
public:
    int solve(int index,int prev,vector<vector<int>>& dp,vector<int>& nums){
        if(index>=nums.size()) return 0;

        if(dp[index][prev+1]!=-1) return dp[index][prev+1];

        int not_take=solve(index+1,prev,dp,nums);

        int take=0;
        if(prev == -1 ||abs(nums[index]-nums[prev]==1)){
            take=1+solve(index+1,index,dp,nums);
        }

        return dp[index][prev+1]=max(take,not_take);
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,dp,nums);
    }
};
