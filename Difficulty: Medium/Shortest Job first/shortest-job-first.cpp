class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        
        sort(bt.begin(),bt.end());
        
        int st=0;
        int twt=0;
        
        for(int i=0;i<n;i++){
            twt+=(st);
            st+=(bt[i]);
        }
        
        return twt/n;
    }
};