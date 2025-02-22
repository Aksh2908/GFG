//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int upperBound(vector<int> v,int x, int low, int high){
        int ans=high+1;
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid]<=x){
                low=mid+1;
            }
            else {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
    int cntEltSmaller(vector<vector<int>> mat, int n, int m, int mid){
        int i;
        int cnt=0;
        for(i=0;i<n;i++){
            cnt+=upperBound(mat[i],mid,0,m-1);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        int n=mat.size(),m=mat[0].size();
        int i,low=INT_MAX,high=INT_MIN;
        for(i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int req=(n*m)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int target=cntEltSmaller(mat,n,m,mid);
            if(target<=req) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends