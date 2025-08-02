class Solution {
  private:
    bool dfs(vector<vector<int>>& adj, vector<int>& path, vector<int>& visited, int src){
        visited[src]=1;
        path[src]=1;
        
        for(auto it:adj[src]){
            if(!visited[it]){
                if(dfs(adj,path,visited,it)) return true;
            }
            else if(path[it]){
                return true;
            }
        }
        
        path[src]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V,vector<int>());
        
        for(int i=0;i<edges.size();i++){
            auto it=edges[i];
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,path,visited,i)) return true;
            }
        }
        return false;
    }
};