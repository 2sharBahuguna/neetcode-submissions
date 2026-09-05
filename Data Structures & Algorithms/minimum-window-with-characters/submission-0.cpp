class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int l = 0, r = 0, counter = t.size(), min_length = INT_MAX, start_idx = 0;

        while (r < s.length()) {
            if (mp[s[r]] > 0) {
                counter--;
            }
            mp[s[r]]--;
            r++;

            while (counter == 0) {
                if (r - l < min_length) {
                    start_idx = l;
                    min_length = r - l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    counter++;
                }
                l++;
            }
        }

        if (min_length != INT_MAX) {
            return s.substr(start_idx, min_length);
        }
        return "";
    }
};
