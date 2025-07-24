class Solution {
  private:
    void dfs(vector<vector<int>>& adj, stack<int>& st, vector<bool>& visited, int src){
        visited[src]=1;
        for(auto it:adj[src]){
            if(!visited[it]) dfs(adj,st,visited,it);
        }
        st.push(src);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V,vector<int>());
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        stack<int> st;
        vector<bool> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]) dfs(adj,st,visited,0);
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};