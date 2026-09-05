class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;

        for(auto it:t){
            mp[it]++;
        }

        for(auto it:s){
            mp[it]--;
            if(mp[it]<0) return false;
        }

        for(auto mapping:mp){
            if(mapping.second>0) return false;
        }
        return true;
    }
};
