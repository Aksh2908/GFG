class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<long long,int> mpp;
        
        mpp[0]=-1;
        
        long long sum=0;
        int maxLen=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            long long rem=sum-k;
            
            if(mpp.find(rem)!=mpp.end()){
                maxLen=max(maxLen,i-mpp[rem]);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        
        return maxLen;
    }
};