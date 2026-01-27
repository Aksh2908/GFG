class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<pair<int,int>> meet(n);
        
        for(int i=0;i<n;i++){
            meet[i]={end[i],start[i]};
        }
        
        sort(meet.begin(),meet.end());
        
        int startTime=-1;
        int endTime=-1;
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(meet[i].first>endTime && meet[i].second>startTime){
                cnt++;
                startTime=meet[i].first;
                endTime=meet[i].second;
            }
        }
        return cnt;
    }
};