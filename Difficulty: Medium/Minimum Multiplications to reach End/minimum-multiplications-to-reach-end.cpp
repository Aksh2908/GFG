// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n=arr.size();
        typedef pair<int,int> p;
        if(start==end) return 0;
        vector<int> dist(100000,INT_MAX);
        queue<p> q;
        q.push({0,start});
        dist[start]=0;
        
        
        while(!q.empty()){
            int dis=q.front().first;
            int num=q.front().second;
            
            q.pop();
            
            for(int i=0;i<n;i++){
                int multi=(num*arr[i])%100000;
                if(multi==end) return dis+1;
                if(dis+1<dist[multi]){
                    dist[multi]=dis+1;
                    q.push({dis+1,multi});
                }
            }
        }
        
        return -1;
    }
};
