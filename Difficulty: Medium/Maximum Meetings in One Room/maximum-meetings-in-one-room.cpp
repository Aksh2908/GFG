//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    static bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        return a.first < b.first;
    }
    
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<pair<int,pair<int,int>>> meetings;
        int n=F.size();
        
        for(int i=0;i<n;i++){
            meetings.push_back({F[i],{S[i],i+1}});
        }
        
        sort(meetings.begin(),meetings.end(),cmp);
        
        int endTime=meetings[0].first;
        
        vector<int> ans;
        ans.push_back(meetings[0].second.second);
        
        for(int i=1;i<n;i++){
            if(meetings[i].second.first>endTime){
                ans.push_back(meetings[i].second.second);
                endTime=meetings[i].first;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends