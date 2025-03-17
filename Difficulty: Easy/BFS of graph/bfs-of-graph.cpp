//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void BFS(vector<vector<int>> &adj, int src, int v, vector<int> &bfs){
        queue<int> q;
        vector<bool> visited(v+1);
        q.push(src);
        visited[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<int> bfs;
        int n=adj.size();
        BFS(adj,0,n,bfs);
        return bfs;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends