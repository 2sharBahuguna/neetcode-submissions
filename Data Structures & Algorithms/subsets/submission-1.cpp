class Solution {
private:
    void solve(int index,vector<vector<int>>& ans,vector<int>& output,vector<int>& nums)
    {
        if(index==nums.size())
        {
            ans.push_back(output);
            return;
        }

        //take
        solve(index+1,ans,output,nums);
        output.push_back(nums[index]);

        //not take
        solve(index+1,ans,output,nums);
        output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0,ans,output,nums);
        return ans;
    }
};
