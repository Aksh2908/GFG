//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int elt=arr[0],cnt=1;
        for(int i=1;i<arr.size();i++){
            if(!cnt){
                elt=arr[i];
                cnt=1;
            }
            else if(arr[i]==elt) cnt++;
            else cnt--;
        }
        cnt=0;
        for(auto it:arr){
            if(it==elt) cnt++;
        }
        return (cnt>(arr.size()/2)) ? elt : -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends