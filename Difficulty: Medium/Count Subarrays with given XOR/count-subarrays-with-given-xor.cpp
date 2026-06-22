class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        
        int cnt=0;
        
        unordered_map<long,int> mpp;
        
        long long XOR=0;
        mpp[0]=1;
        
        for(int i=0;i<n;i++){
            XOR^=arr[i];
            
            long long rem=XOR^k;
            
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            
            mpp[XOR]++;
        }
        
        return cnt;
    }
};