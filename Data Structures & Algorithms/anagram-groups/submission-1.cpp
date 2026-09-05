class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(auto it:strs){
            string toSort=it;
            sort(toSort.begin(),toSort.end());
            mp[toSort].push_back(it);
        }

        vector<vector<string>> res;

        for(auto it:mp){
            res.push_back(it.second);
        }

        return res;
    }
};
