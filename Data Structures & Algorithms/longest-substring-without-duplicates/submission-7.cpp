class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int l=0;
        int r=0;
        int maxi=0;
        while(r<s.length()){
            mp[s[r]]++;

            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }

            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
