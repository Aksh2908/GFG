class Solution {
  private:
    bool dfs(vector<vector<int>> &adj, vector<int>& visited, int src, int prev){
        visited[src]=1;
        
        for(auto it:adj[src]){
            if(visited[it]==0){
                if(dfs(adj,visited,it,src)) return true;
            }
            else if(it!=prev) return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V,vector<int>());
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,visited,i,-1)) return true;
            }
        }
        
        return false;
    }
};