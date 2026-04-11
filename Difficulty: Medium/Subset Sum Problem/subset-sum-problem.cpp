class Solution {
  private:
    bool solve(vector<int>& arr, int sum, int n, vector<vector<int>>& dp){
        if(sum==0) return true;
        if(n==0){
            if(sum-arr[0]==0) return true;
            return false;
        }
        if(dp[n][sum]!=-1) return dp[n][sum];
        int pick=0;
        int notPick=solve(arr,sum,n-1,dp);
        if(arr[n]<=sum) pick=solve(arr,sum-arr[n],n-1,dp);
        return dp[n][sum]=(pick || notPick);
        
        
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(arr,sum,n-1,dp);
    }
};