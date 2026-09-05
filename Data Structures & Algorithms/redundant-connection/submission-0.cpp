class DisJointSet{
    vector<int> parent;
    vector<int> rank;

    public:
    DisJointSet(int n)
    {
        rank.resize(n,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findParent(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }

    bool Unionbyrank(int u,int v)
    {
        int ultimate_parent_u=findParent(u);
        int ultimate_parent_v=findParent(v);

        if(ultimate_parent_u==ultimate_parent_v) return false;

        if(rank[ultimate_parent_u] > rank[ultimate_parent_v]){
            parent[ultimate_parent_v] = ultimate_parent_u;
        }
        else if(rank[ultimate_parent_u] < rank[ultimate_parent_v]){
            parent[ultimate_parent_u] = ultimate_parent_v;
        }
        else{
            parent[ultimate_parent_u] = ultimate_parent_v;
            rank[ultimate_parent_v]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisJointSet ds(n+1);
        for(auto it:edges)
        {
            if(ds.Unionbyrank(it[0],it[1])==false)
            {
                return {it[0],it[1]};
            }
        }
        return {};
    }
};
