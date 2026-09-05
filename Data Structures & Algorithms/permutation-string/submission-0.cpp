class Solution {
private:
    bool checkInclusionHelper(const string& s1, const string& s2) {
        vector<int> count(26, 0);

        for (char c : s1) {
            count[c - 'a']++;
        }

        int left = 0, right = 0;
        int size = s1.length();
        int remaining = size;

        while (right < s2.length()) {
            if (count[s2[right] - 'a'] > 0) {
                count[s2[right] - 'a']--;
                remaining--;
                right++;
            } else if (left == right) {
                left++;
                right++;
            } else {
                count[s2[left] - 'a']++;
                remaining++;
                left++;
            }

            if (remaining == 0) {
                return true;
            }
        }

        return false;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        return checkInclusionHelper(s1, s2);
    }
};
