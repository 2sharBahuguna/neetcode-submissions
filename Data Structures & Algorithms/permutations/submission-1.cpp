class Solution {
private:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& output,map<int,bool> mp){
        if(output.size()==nums.size()){
            ans.push_back(output);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]]){
                mp[nums[i]]=true;
                output.push_back(nums[i]);
                solve(nums,ans,output,mp);
                mp[nums[i]]=false;
                output.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        map<int,bool> mp;

        solve(nums,ans,output,mp);
        return ans;
    }
};
