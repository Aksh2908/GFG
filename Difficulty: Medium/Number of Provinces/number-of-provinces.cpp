// User function Template for C++
class disjoint{
    public:
        vector<int> parent,size;
        disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        
        int findParent(int u){
            if(u==parent[u]) return u;
            return parent[u]=findParent(parent[u]);
        }
        
        void unionBySize(int u, int v){
            int pu=findParent(u);
            int pv=findParent(v);
            if(size[pu]<size[pv]){
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else{
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> adjL(V);
        int i,j;
        disjoint ds(V);
        
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(adj[i][j] && i!=j){
                    ds.unionBySize(i,j);
                }
            }
        }
        
        
        int cnt=0;
        
        for(int i=0;i<V;i++){
            if(ds.findParent(i)==i) cnt++;
        }
        return cnt;
    }
};