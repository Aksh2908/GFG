class Solution {
  int solve(vector<int>& height, vector<int>& dp, int idx){
      if(idx==0) return 0;
      if(dp[idx]!=-1) return dp[idx];
      int left=solve(height,dp,idx-1)+abs(height[idx]-height[idx-1]);
      int right=INT_MAX;
      if(idx>1){
          right=solve(height,dp,idx-2)+abs(height[idx]-height[idx-2]);
      }
      return dp[idx]=min(left,right);
  }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n+1,-1);
        return solve(height,dp,n-1);
    }
};