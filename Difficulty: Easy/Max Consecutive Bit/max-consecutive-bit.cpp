class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        int cnt=0;
        int maxi=0;
        int maximum=0;
        int elt=arr[0];
        
        for(int i=0;i<n;i++){
            if(arr[i]==elt){
                cnt++;
            }
            else{
                maxi=max(maxi,cnt);
                cnt=1;
                elt=arr[i];
            }
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};