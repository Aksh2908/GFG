//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int power(int n, int m, int x){
        int i,p=1;
        for(i=1;i<=n;i++){
            p=p*m;
            if(p>x) return 2;
        }
        if(p==x) return 1;
        return 0;
    }
    int nthRoot(int n, int m) {
        int low=1,high=m;
        while(low<=high){
            int mid=(low+high)/2;
            if(power(n,mid,m)==1) return mid;
            if(power(n,mid,m)==2) high=mid-1;
            else if(power(n,mid,m)==0)low=mid+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends