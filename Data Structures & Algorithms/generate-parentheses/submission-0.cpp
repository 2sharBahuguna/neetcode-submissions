class Solution {
private:
    void solve(int open,int closed,int n,string& st,vector<string>& ans){
        if(open==closed && open==n){
            ans.push_back(st);
            return;
        }

        if(open<n){
            st+='(';
            solve(open+1,closed,n,st,ans);
            st.pop_back();
        }

        if(closed<open){
            st+=')';
            solve(open,closed+1,n,st,ans);
            st.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st;
        solve(0,0,n,st,ans);
        return ans;
    }
};
