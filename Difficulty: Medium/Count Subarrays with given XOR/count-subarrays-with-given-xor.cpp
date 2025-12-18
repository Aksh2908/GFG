class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int cnt=0;
        int Xor=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            Xor^=arr[i];
            
            int diff=Xor^k;
            if(mpp.find(diff)!=mpp.end()){
                cnt+=mpp[diff];
            }
            mpp[Xor]++;
        }
        return cnt;
    }
};