class Solution {
  private:
    int solve(vector<int>& arr, int target, int n, vector<vector<int>>& dp){
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0] && arr[0]<=target) dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int pick=0;
                int notPick=dp[i-1][j];
                if(arr[i]<=j) pick=dp[i-1][j-arr[i]];
                dp[i][j]=(pick+notPick);
            }
        }
        return dp[n-1][target];
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int cnt=0;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        return solve(arr,target,n,dp);
    }
};