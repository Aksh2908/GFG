class Solution {
  private:
    bool possible(vector<int>& stalls, int mid, int k){
        int cnt=1;
        int last=stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=mid){
                cnt++;
                last=stalls[i];
            }
        }
        
        if(cnt>=k) return true;
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        
        sort(stalls.begin(),stalls.end());
        
        int low=1,high=stalls[n-1]-stalls[0];
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(possible(stalls,mid,k)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return high;
    }
};