class Solution {
  private:
    int lesserEqual(vector<int>& mat, int mid){
        return upper_bound(mat.begin(),mat.end(),mid)-mat.begin();
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        int low=mat[0][0],high=mat[0][m-1];
        
        for(int i=1;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        
        int median=(m*n+1)/2;
        while(low<=high){
            int mid=(low+high)/2;
            
            int cnt=0;
            
            for(int i=0;i<n;i++){
                cnt+=lesserEqual(mat[i],mid);
            }
            if(cnt<median) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
