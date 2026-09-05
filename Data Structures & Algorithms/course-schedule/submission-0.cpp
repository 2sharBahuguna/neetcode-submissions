class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int> adj[num];

        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<int> indegree(num, 0);
        for(int i=0;i<num;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<num;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        int count=0;

        while(!q.empty())
        {
            int value = q.front();
            q.pop();
            count++;
            for(auto it:adj[value])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(count==num) return true;
        return false;
    }
};
