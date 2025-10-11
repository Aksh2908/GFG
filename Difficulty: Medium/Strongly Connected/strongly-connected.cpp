//Position this line where user code will be pasted.
class Solution {
  private:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, stack<int>& st, int src){
        visited[src]=1;
        for(auto it:adj[src]){
            if(!visited[it]){
                dfs(adj,visited,st,it);
            }
        }
        st.push(src);
    }
    
    void dfsReversed(vector<vector<int>>& adj, vector<int>& visited, int src){
        visited[src]=1;
        for(auto it:adj[src]){
            if(!visited[it]){
                dfsReversed(adj,visited,it);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int v=adj.size();
        
        // sort accprding to finishing time
        stack<int> st;
        vector<int> visited(v,0);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(adj,visited,st,i);
            }
        }
        
        vector<vector<int>> adjReversed(v,vector<int>());
        // Reverse Graph
        for(int i=0;i<v;i++){
            visited[i]=0;
            for(auto it:adj[i]){
                adjReversed[it].push_back(i);
            }
        }
        
        // DFS on reversed graph
        int cnt=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                dfsReversed(adjReversed,visited,node);
                cnt++;
            }
        }
        
        return cnt;
    }
};