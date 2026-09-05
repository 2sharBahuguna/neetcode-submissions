class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;

        for(auto it:s){
            mp[it]++;
        }

        for(auto it:t){
            mp[it]--;
        }

        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second!=0) return false;
        }
        return true;

    }
};
