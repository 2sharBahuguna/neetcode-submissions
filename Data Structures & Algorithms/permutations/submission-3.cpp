class Solution {
private:
    void solve(vector<int>& nums,vector<int>& output,vector<vector<int>>& ans,map<int,bool> mp){
        if(output.size()==nums.size()){
            ans.push_back(output);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]]){
                mp[nums[i]]=true;
                output.push_back(nums[i]);
                solve(nums,output,ans,mp);  
                output.pop_back();
                mp[nums[i]]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,bool> mp;
        vector<int> output;
        vector<vector<int>> ans;
        solve(nums,output,ans,mp);
        return ans;
    }
};
