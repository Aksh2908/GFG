//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {
  public:
    vector<int> candyStore(int candies[], int N, int K) {
        sort(candies,candies+N);
        
        int mini=0,buy=0,free=N-1;
        while(buy<=free){
            mini+=candies[buy];
            buy++;
            free-=K;
        }
        
        int maxi=0;
        buy=N-1,free=0;
        while(free<=buy){
            maxi+=candies[buy];
            buy--;
            free+=K;
        }
        
        return {mini,maxi};
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends