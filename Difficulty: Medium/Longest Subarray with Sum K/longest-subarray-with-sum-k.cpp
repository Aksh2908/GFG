//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long,int> mpp;
        int n=arr.size(),i;
        long long sum=0;
        int maxLen=0;
        if(!n) return 0;
        mpp[0]=-1;
        for(i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxLen=max(maxLen,i+1);
            }
            long long diff=sum-k;
            if(mpp.find(diff)!=mpp.end()){
                maxLen=max(maxLen,i-mpp[diff]);
            }
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }
        return (int)maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends