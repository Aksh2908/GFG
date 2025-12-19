class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        
        int maxLen=0;
        long long sum=0;
        if(!n) return 0;
        unordered_map<long long,int> mpp;
        mpp[0]=-1;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxLen=max(maxLen,i+1);
            }
            
            int diff=sum-k;
            
            if(mpp.find(diff)!=mpp.end()){
                maxLen=max(maxLen,i-mpp[diff]);
            }
            
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return (int)maxLen;
    }
};