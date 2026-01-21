class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        if(n==1) return 0;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        int ans=0;
        int sum=0;
        
        while(pq.size()!=1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            sum=first+second;
            pq.push(sum);
            ans+=sum;
        }
        
        return ans;
    }
};