class Solution {
  private:
    int solve(vector<int> &val, vector<int> &wt, int idx, int W,vector<vector<int>>& dp){
        if(idx==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[idx][W]!=-1) return dp[idx][W];
        int pick=INT_MIN,notPick=INT_MIN;
        notPick=solve(val,wt,idx-1,W,dp);
        if(wt[idx]<=W) pick=val[idx]+solve(val,wt,idx-1,W-wt[idx],dp);
        return dp[idx][W]=max(pick,notPick);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return solve(val,wt, n-1, W,dp);
    }
};