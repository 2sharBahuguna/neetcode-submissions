class Solution {
private:
    bool diff(const string& a, const string& b)
    {
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) // Assuming both strings have the same length
        {
            if(a[i] != b[i])
            {
                cnt++;
            }
            if (cnt > 1) return false; // Early exit if more than one character differs
        }
        return cnt == 1;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0; // endWord not in wordList
        }

        // Create an adjacency list
        unordered_map<string, vector<string>> mp;
        wordList.push_back(beginWord); // Include beginWord in wordList for adjacency creation
        int n = wordList.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(diff(wordList[i], wordList[j])){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // BFS to find the shortest path
        unordered_map<string, bool> vis;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        vis[beginWord] = true;

        while(!q.empty())
        {
            string node=q.front().first;
            int step=q.front().second;
            q.pop();

            for(const auto& neighbor : mp[node])
            {
                if(neighbor == endWord) return step + 1;
                if(!vis[neighbor])
                {
                    vis[neighbor] = true;
                    q.push({neighbor, step + 1});
                }
            }
        }

        return 0; // No path found
    }
};
