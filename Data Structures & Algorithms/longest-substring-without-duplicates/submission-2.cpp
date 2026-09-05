class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxP=0;
        map<int,int> mp;
        
        while(r<s.length())
        {
            mp[s[r]]++;
            while(mp[s[r]]>1)
            {
                mp[s[l]]--;
                l++;
            }

            maxP=max(maxP,r-l+1);
            r++;
        }
        return maxP;
    }
};
