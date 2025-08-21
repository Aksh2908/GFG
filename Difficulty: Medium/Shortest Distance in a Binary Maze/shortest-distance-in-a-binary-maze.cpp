// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(source==destination) return 0;
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{source.first,source.second}});
        
        vector<int> row={0,1,0,-1};
        vector<int> col={1,0,-1,0};
        
        while(!q.empty()){
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int ni=r+row[i];
                int nj=c+col[i];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]){
                    if(d+1<dist[ni][nj]){
                        dist[ni][nj]=d+1;
                        if(ni==destination.first && nj==destination.second){
                            return dist[ni][nj];
                        }
                        q.push({d+1,{ni,nj}});
                    }
                }
            }
        }
        
        if(dist[destination.first][destination.second]==INT_MAX) return -1;
        return dist[destination.first][destination.second];
    }
};
