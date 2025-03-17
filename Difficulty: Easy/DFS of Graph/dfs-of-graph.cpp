//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(vector<vector<int>>& adj, vector<int> &dfs, int src, vector<int> &visited){
        visited[src]=1;
        dfs.push_back(src);
        for(auto it:adj[src]){
            if(!visited[it]) DFS(adj,dfs,it,visited);
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> dfs;
        int n=adj.size();
        vector<int> visited(n+1);
        DFS(adj,dfs,0,visited);
        return dfs;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends