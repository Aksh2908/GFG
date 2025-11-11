class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int cnt=0;
        int xorr=0;
        
        unordered_map<int,int> mpp;
        mpp[xorr]++;
        
        for(int i=0;i<n;i++){
            xorr^=arr[i]; //prefix xor
            int rem=k^xorr;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[xorr]++;
        }
        
        return cnt;
    }
};