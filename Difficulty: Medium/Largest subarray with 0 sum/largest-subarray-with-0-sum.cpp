class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        
        int maxLen=0;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                maxLen=max(maxLen,i+1);
            }
            else if(mpp.find(sum)!=mpp.end()){
                maxLen=max(maxLen,i-mpp[sum]);
            }
            else mpp[sum]=i;
        }
        return maxLen;
    }
};