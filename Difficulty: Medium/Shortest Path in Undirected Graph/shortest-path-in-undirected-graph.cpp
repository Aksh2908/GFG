class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int v=adj.size(); // no of vertices
        vector<int> dist(v,INT_MAX);
        
        queue<pair<int,int>> q; // {node,weight}
        q.push({src,0});
        dist[src]=0;
        
        while(!q.empty()){
            int node=q.front().first;
            int wt=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[it]==INT_MAX && dist[it]>dist[node]+1){
                    dist[it]=dist[node]+1;
                    q.push({it,dist[it]});
                }
            }
        }
        
        for(int i=0;i<v;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};