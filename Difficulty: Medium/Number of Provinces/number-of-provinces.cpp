//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  private:
    void dfs(int src, vector<int>& visited, vector<vector<int>>& adj){
        visited[src]=1;
        for(auto it:adj[src]){
            if(!visited[it]) dfs(it,visited,adj);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>> adjL(V);
        int i,j;
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(adj[i][j] && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int> visited(V);
        for(i=0;i<V;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adjL);
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends