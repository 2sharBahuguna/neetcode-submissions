class Solution {
private:
    int solve(int prev,int index,vector<int>& nums,vector<vector<int>>& dp){
        if(index>=nums.size()) return 0;

        if(dp[prev+1][index]!=-1) return dp[prev+1][index];

        int not_take=solve(prev,index+1,nums,dp);
        int take=0;
        if(prev==-1 ||abs(nums[prev]-nums[index])==1){
            take=1+solve(index,index+1,nums,dp);
        }

        return dp[prev+1][index]=max(take,not_take);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return solve(-1,0,nums,dp);
    }
};
