//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int x;
        if(num&(1<<i-1)) x=1;
        else x=0;
        int y=num|(1<<i-1);
        int z=num&(~(1<<i-1));
        cout << x << " " << y << " " << z << " ";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends