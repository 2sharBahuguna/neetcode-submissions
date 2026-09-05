class Solution {
private:
    void solve(int index,string s,vector<vector<string>>& ans,vector<string>& output)
    {
        if(index==s.length())
        {
            ans.push_back(output);
            return;
        }

        for(int i=index;i<s.length();i++)
        {
            if(palindrome(s,index,i))
            {
                output.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,output);
                output.pop_back();
            }
        }
    }

    bool palindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(0,s,ans,output);
        return ans;
    }
};
