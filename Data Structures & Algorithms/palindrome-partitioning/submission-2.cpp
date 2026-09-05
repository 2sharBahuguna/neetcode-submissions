class Solution {
private:
    void solve(int index,vector<string>& output,vector<vector<string>>& ans,string s){
        if(index==s.length()){
            ans.push_back(output);
            return;
        }

        for(int i=index;i<s.length();i++){
            if(isPalindrome(index,i,s)){
                output.push_back(s.substr(index,i-index+1));
                solve(i+1,output,ans,s);
                output.pop_back();
            }
        }
    }
    bool isPalindrome(int start,int end, string s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> output;
        vector<vector<string>> ans;
        solve(0,output,ans,s);
        return ans;
    }
};
