class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int l=0;
        int r=0;
        int max_count=0;
        int result=0;
        while(r<s.length()){
            mp[s[r]]++;
            max_count=max(max_count,mp[s[r]]);

            if(r-l+1-max_count>k){
                mp[s[l]]--;
                l++;
            }

            result=max(result,r-l+1);
            r++;
        }
        return result;

    }
};
