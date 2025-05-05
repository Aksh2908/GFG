//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> ans;
        int n=end.size();
        
        for(int i=0;i<n;i++){
            ans.push_back({start[i],end[i]});
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
        int endTime=ans[0].second;
        
        int cnt=1;
        
        for(int i=1;i<n;i++){
            if(ans[i].first>endTime){
                cnt++;
                endTime=ans[i].second;
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends