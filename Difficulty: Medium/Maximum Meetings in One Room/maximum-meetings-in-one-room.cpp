class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        int n=s.size();
        
        vector<pair<int,pair<int,int>>> ds;
        
        for(int i=0;i<n;i++){
            ds.push_back({f[i],{i+1,s[i]}});
        }
        
        sort(ds.begin(),ds.end());
        
        int endtime=-1;
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(endtime<ds[i].second.second){
                ans.push_back(ds[i].second.first);
                endtime=ds[i].first;
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};