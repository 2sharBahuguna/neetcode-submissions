class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        //adjacency list
        //indegree
        //push indegree==0
        //while(!q.empty())

        vector<vector<int>> adj(n);
        for(int i=0;i<arr.size();i++)
        {
            adj[arr[i][1]].push_back(arr[i][0]);
        }

        vector<int> indegree(n,0);

        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty())
        {
            int value=q.front();
            q.pop();
            count++;
            for(auto it:adj[value])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(count==n) return true;
        return false;
    }
};
