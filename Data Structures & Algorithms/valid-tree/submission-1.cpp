class Solution {
private:
    bool hasCycle(int node,int parent,vector<int>& visited,vector<vector<int>>& adj)
    {
        if(visited[node])
        {
            return true;
        }

        visited[node]=1;

        for(auto it:adj[node])
        {
            if(it!=parent && hasCycle(it,node,visited,adj)){
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==0) return false;
        vector<vector<int>> adj(n);


        //a tree doesnt have a attached nodes and they dont have seperate nodes without any edges bw them
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        
        //to check if has cycle
        if(hasCycle(0,-1,visited,adj)){
            return false;
        }


        //not seperate node
        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;

    }
};
