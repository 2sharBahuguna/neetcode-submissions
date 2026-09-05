class Solution {
private:
    void solve(vector<vector<int>>& ans,vector<int>& output,unordered_map<int,bool> mp,vector<int> nums)
    {
        if(output.size()==nums.size())
        {
            ans.push_back(output);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==false)
            {
                output.push_back(nums[i]);
                mp[nums[i]]=true;
                solve(ans,output,mp,nums);

                mp[nums[i]]=false;
                output.pop_back();
            }
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,bool> mp;
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans,output,mp,nums);
        return ans;
    }
};
