// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        typedef pair<int,pair<int,int>> pp;
        
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,{source.first,source.second}});
        visited[source.first][source.second]=1;
        
        vector<int> row={0,-1,0,1};
        vector<int> col={-1,0,1,0};
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            if(r==destination.first && c==destination.second) return dist;
            pq.pop();
            
            for(int i=0;i<4;i++){
                int ni=row[i]+r;
                int nj=col[i]+c;
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1 && !visited[ni][nj]){
                    pq.push({dist+1,{ni,nj}});
                    visited[ni][nj]=1;
                }
            }
        }
        return -1;
    }
};
