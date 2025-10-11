// User function Template for C++
class disjoint{
    private:
        vector<int> rank;
        vector<int> size;
        vector<int> parent;
    public:
    disjoint(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }

    void UnionByRank(int u, int v){
        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }

    void UnionBySize(int u, int v){
        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj;
        for(auto it:edges){
                adj.push_back({it[2],it[0],it[1]});
        }
        
        sort(adj.begin(),adj.end());
        
        disjoint ds(V);
        int sum=0;
        
        for(auto it:adj){
            int w=it[0];
            int u=it[1];
            int v=it[2];
            
            if(ds.findParent(u)!=ds.findParent(v)){
                sum+=w;   
                ds.UnionBySize(u,v);
            }
        }
        return sum;
    }
};