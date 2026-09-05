class Solution {
private:
    void solve(int index,int sum,vector<vector<int>>& ans,vector<int>& candidates,vector<int>& output,int target)
    {
        if(target==0)
        {
            ans.push_back(output);
            return;
        }

        if(target<0 || index==candidates.size())
        {
            return;
        }

        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;
            output.push_back(candidates[i]);
            solve(i+1,sum,ans,candidates,output,target-candidates[i]);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(),candidates.end());
        solve(0,0,ans,candidates,output,target);
        return ans;
    }
};
