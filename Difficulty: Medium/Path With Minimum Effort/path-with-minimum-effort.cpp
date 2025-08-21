
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        vector<vector<int>> diff(rows,vector<int>(columns,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, 
               vector<pair<int,pair<int,int>>>, 
               greater<pair<int,pair<int,int>>>> pq;

        
        pq.push({0,{0,0}});//{diff,{row,col}}
        diff[0][0]=0;
        
        vector<int> row={0,1,0,-1};
        vector<int> col={1,0,-1,0};
        
        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            
            pq.pop();
            
            for(int i=0;i<4;i++){
                int ni=r+row[i];
                int nj=c+col[i];
                if(ni>=0 && ni<rows && nj>=0 && nj<columns){
                    if(max(d,abs(heights[ni][nj]-heights[r][c]))<diff[ni][nj]){
                        diff[ni][nj]=max(d,abs(heights[ni][nj]-heights[r][c]));
                        pq.push({diff[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return diff[rows-1][columns-1];
    }
};
