// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> ans(n+1);
        
        for(int i=0;i<=n;i++) ans[i]=i;
        
        for(int i=2;i<=n;i++){
            if(ans[i]==i){
                for(int j=i*i;j<=n;j=j+i){
                    if(ans[j]==j){
                        ans[j]=i;
                    }
                }
            }
        }
        
        return ans;
    }
};