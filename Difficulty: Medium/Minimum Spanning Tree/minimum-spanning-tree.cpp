class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        typedef pair<int,int> pp;
        vector<vector<pp>> adj(V,vector<pp>());
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> visited(V,0);
        
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,0}); //{wt,node};
        
        int sum=0;
        
        while(!pq.empty()){
            int w=pq.top().first;
            int n=pq.top().second;
            if(!visited[n]){
                sum+=w;
                visited[n]=1;
            }
            
            pq.pop();
            
            for(auto it:adj[n]){
                if(!visited[it.first]){
                    pq.push({it.second,it.first});
                }   
            }
        }
        return sum;
    }
};