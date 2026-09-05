class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0) return false;
        vector<vector<int>> adj(n);

        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n,0);

        if(hasCycle(adj,visited,-1,0))
        {
            return false;
        }

        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }

    private:
    bool hasCycle(vector<vector<int>>& adj,vector<int>& visited,int parent,int node)
    {
        if(visited[node])
        {
            return true;
        }

        visited[node]=1;

        for(auto it:adj[node])
        {
            if(it!=parent && hasCycle(adj, visited, node, it))
            {
                return true;
            }
        }
        return false;
    }
};
