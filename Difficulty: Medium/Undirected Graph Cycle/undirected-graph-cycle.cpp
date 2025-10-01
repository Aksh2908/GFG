class Solution {
  private:
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int src, int prev){
        visited[src]=1;
        for(auto it:adj[src]){
            if(!visited[it]){
                if(dfs(adj,visited,it,src)) return true;
            }
            else if(it!=prev) return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V,vector<int>());
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,visited,i,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};