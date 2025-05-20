//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        for(int k=i;k<j;k++){
            int temp = solve(arr, i, k, dp)+ solve(arr, k+1, j, dp)+ (arr[i-1]*arr[j]*arr[k]);
            dp[i][j]=min(temp,dp[i][j]);
        }
        return dp[i][j];
    }

  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return solve(arr, 1, n-1, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends