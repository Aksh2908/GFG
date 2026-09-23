class Solution {
  private:
    void solve(vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<string>& ans, string& temp, int r, int c, vector<int>& row, vector<int>& col, int n){
        if(maze[r][c]==0) return;
        
        if(r==n-1 && c==n-1){
            ans.push_back(temp);
            return;
        }
        
        
        if(!visited[r][c]){
            
            visited[r][c]=1;
            
            for(int i=0;i<4;i++){
                int nx=r+row[i];
                int ny=c+col[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(nx==r && ny==c-1) temp+='L';
                    if(nx==r-1 && ny==c) temp+='U';
                    if(nx==r && ny==c+1) temp+='R';
                    if(nx==r+1 && ny==c) temp+='D';
                    
                    solve(maze,visited,ans,temp,nx,ny,row,col,n);
                    
                    temp.pop_back();
                }
            }
            
            visited[r][c]=0;
        }
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
         int n=maze.size();
         
         vector<vector<bool>> visited(n,vector<bool>(n,0));
         
         vector<string> ans;
         
         string temp="";
         
         vector<int> row={0,-1,0,1};
         vector<int> col={-1,0,1,0};
         
         solve(maze,visited,ans,temp,0,0,row,col,n);
         
         sort(ans.begin(), ans.end());
         
         return ans;
    }
};