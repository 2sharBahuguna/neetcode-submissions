class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length=0;

        int l=0;
        int r=0;

        map<char,int> mp;

        while(r<s.length())
        {
            mp[s[r]]++;

            while(mp[s[r]]>1)
            {
                mp[s[l]]--;
                l++;
            }

            max_length=max(max_length,r-l+1);
            r++;
        }

        return max_length;
        
    }
};
