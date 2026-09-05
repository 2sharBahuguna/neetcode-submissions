class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int result=0;
        int max_count=0;
        map<int,int> mp;

        while(r<s.length())
        {
            mp[s[r]-'A']++;

            max_count=max(max_count,mp[s[r]-'A']);

            if(r-l+1-max_count>k)
            {
                mp[s[l]-'A']--;
                l++;
            }

            result=max(result,r-l+1);
            r++;
        }

        return result;
    }
};
