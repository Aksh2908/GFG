//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int i=0,j=0;
        int n1=a.size(),n2=b.size();
        int cnt=0,prev;
        while(i<n1 && j<n2){
            cnt++;
            if(a[i]<=b[j]){
                prev=a[i];
                i++;
            }
            else{
                prev=b[j];
                j++;
            }
            if(cnt==k){
               return prev;
            }
        }
        while(i<n1){
            cnt++;
            prev=a[i];
            i++;
            if(cnt==k){
               return prev;
            }
        }
        while(j<n2){
            cnt++;
            prev=b[j];
                j++;
            if(cnt==k){
               return prev;
            }
        }
        return prev;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends