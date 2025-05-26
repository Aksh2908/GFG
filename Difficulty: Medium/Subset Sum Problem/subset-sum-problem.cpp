class Solution {
  public:
    bool solve(vector<int> arr, int sum, int n, vector<vector<bool>>& dp){
        bool pick = false;
        for(int i=0;i<=n;i++) dp[i][0]=true;
        
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if (arr[i] <= j)
                    pick = dp[i-1][j-arr[i]];
                bool notPick = dp[i-1][j];
                dp[i][j]=pick || notPick;
            }
        }
        return dp[n][sum];
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool> (sum+1,0));
        return solve(arr, sum, n - 1,dp);
    }
};