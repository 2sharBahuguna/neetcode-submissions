class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;

        for(int i=0;i<strs.size();i++){
            string str= strs[i];
            string sorted=str;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }

};
