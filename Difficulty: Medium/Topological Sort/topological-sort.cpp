class Solution {
  private:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, stack<int>& st, int src){
        visited[src]=1;
        
        for(auto it:adj[src]){
            if(!visited[it]) dfs(adj,visited,st,it);
        }
        
        st.push(src);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V,vector<int>());
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        stack<int> st;
        
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]) dfs(adj,visited,st,i);
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};