class Solution {
public:
    bool isPalindrome(string s) {

        string t="";

        for(auto it:s){
            if(!isalnum(it)) continue;
            t+=it;
        }

        int l=0;
        int r=t.length()-1;


        while(l<=r){
            if( tolower(t[l++])!=tolower(t[r--])) return false;
        }

        return true;


    }
};
