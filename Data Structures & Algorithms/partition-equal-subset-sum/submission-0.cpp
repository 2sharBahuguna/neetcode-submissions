class Solution {
private:
    bool solve(int index,int k,vector<vector<int>>& dp,vector<int>& arr)
    {
        //base case
        if(k==0) return true;

        if(index<0) return false;

        if(dp[index][k]!=-1) return dp[index][k];

        bool not_take=solve(index-1,k,dp,arr);

        bool take=false;

        if(arr[index]<=k)
        {
            take=solve(index-1,k-arr[index],dp,arr);
        }

        return dp[index][k]=take || not_take;
    } 
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }

        if(sum%2==1) return false;

        else sum/=2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,dp,nums);
    }
};
