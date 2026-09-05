class Solution {
public:
    void solve(vector<int> nums,int index,vector<int> output,vector<vector<int>>& ans)
    {
        if(index>= nums.size())
        {
            ans.push_back(output);
            return;
        }

        //exclude
        solve(nums,index+1,output,ans);

        //include
        int element= nums[index];
        output.push_back(element);
        solve(nums,index+1,output,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<int> output;
        vector<vector<int>> ans;
        solve(nums,index,output,ans);

        return ans;
    }
};
