// User function Template for C++

class Solution {
  private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int base_i, int base_j, vector<int>& row, vector<int>& col, int n, int m, vector<pair<int,int>>& shape){
        visited[i][j]=1;
        shape.push_back({i-base_i,j-base_j});
        for(int k=0;k<4;k++){
            int ni=i+row[k];
            int nj=j+col[k];
            
            if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj] && grid[ni][nj]){
                dfs(grid,visited,ni,nj,base_i,base_j,row,col,n,m,shape);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> row={0,-1,0,1};
        vector<int> col={-1,0,1,0};
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>> shape;
                if(!visited[i][j] && grid[i][j]){
                    dfs(grid,visited,i,j,i,j,row,col,n,m,shape);
                    st.insert(shape);
                }
            }
        }
        
        return st.size();
    }
};
