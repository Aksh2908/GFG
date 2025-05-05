//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int,int>> ans;
        int n=finish.size();
        
        for(int i=0;i<n;i++){
            ans.push_back({start[i],finish[i]});
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
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends