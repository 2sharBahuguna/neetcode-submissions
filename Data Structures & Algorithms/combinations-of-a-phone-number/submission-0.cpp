class Solution {
private:
    void solve(int index,string& digits,string curr,vector<string>& ans,unordered_map<char,string>& mp)
    {
        if(curr.size()==digits.size())
        {
            ans.push_back(curr);
            return;
        }

        for(char c:mp.at(digits[index]))
        {
            solve(index+1,digits,curr+c,ans,mp);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.size()==0) return ans;

        unordered_map<char,string> mp={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        string curr="";
        solve(0,digits,curr,ans,mp);
        return ans;
    }
};
