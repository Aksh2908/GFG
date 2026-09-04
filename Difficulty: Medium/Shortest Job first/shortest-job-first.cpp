class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        
        sort(bt.begin(),bt.end());
        
        int wt=0;
        int st=0;
        
        for(int i=0;i<n;i++){
            st+=(bt[i]);
            wt+=(st-bt[i]);
        }
        
        return (wt/n);
    }
};