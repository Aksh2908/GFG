//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src,vector<int>& visited, vector<vector<int>>& adj, int prev){
        visited[src]=1;
        for(auto it:adj[src]){
            if(!visited[it]){
                if(dfs(it,visited,adj,src)) return true;
            }
            else if(it!=prev) return true;
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int> visited(v);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(dfs(i,visited,adj,-1)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends