class Solution {
private:
    bool diff(string a,string b)
    {
        int cnt=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                cnt++;
            }
            if(cnt>1) return false;
        }
        return cnt==1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        wordList.push_back(beginWord);
        int n=wordList.size();
        map<string,vector<string>> mp;
        
        //make map;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(diff(wordList[j],wordList[i])){
                    mp[wordList[j]].push_back(wordList[i]);
                    mp[wordList[i]].push_back(wordList[j]);
                }
            }
        }
        map<string,bool> vis;
        vis[beginWord]=true;
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty())
        {
            string node=q.front().first;
            int step=q.front().second;
            q.pop();
            

            for(auto it:mp[node])
            {
                if(it==endWord)
                {
                    return step+1;
                }
                if(!vis[it])
                {
                    vis[it]=true;
                    q.push({it,step+1});
                }
            }
        }

        return 0;

    }
};
