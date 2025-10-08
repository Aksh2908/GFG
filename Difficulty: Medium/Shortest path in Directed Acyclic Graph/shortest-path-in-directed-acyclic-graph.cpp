// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>()); //u->{v,wt}
        
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
        vector<int> dist(V,INT_MAX);
        
        queue<pair<int,int>> q; // {node,weight}
        q.push({0,0});
        dist[0]=0;
        
        while(!q.empty()){
            int node=q.front().first;
            int wt=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                int u=it.first;
                int w=it.second;
                if(dist[u]>dist[node]+w){
                    dist[u]=dist[node]+w;
                    q.push({u,dist[u]});
                }
            }
        }
        // O(V+E)
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        // O(V)
        return dist;
    }
};
