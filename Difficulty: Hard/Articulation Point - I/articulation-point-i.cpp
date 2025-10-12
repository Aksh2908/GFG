// User function Template for C++

class Solution {
  private:
    int timer=0;
    
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited, vector<int>& mark, vector<int>& time, vector<int>& low){
        visited[node]=1;
        time[node]=timer;
        low[node]=timer;
        timer++;
        
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!visited[it]){
                dfs(it,node,adj,visited,mark,time,low);
                low[node]=min(low[node],low[it]);
                
                if(low[it]>=time[node] && parent != -1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],time[it]);
            }
        }
        if(child>1 && parent == -1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        vector<int> mark(V,0);
        vector<int> time(V);
        vector<int> low(V);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,adj,visited,mark,time,low);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i]){
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0) return {-1};
        return ans;
    }
};