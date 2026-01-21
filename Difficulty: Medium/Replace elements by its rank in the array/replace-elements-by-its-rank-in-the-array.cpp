// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        
        int rank=1;
        
        vector<int> ans(N,-1);
        
        vector<pair<int,int>> sorted(N);
        
        for(int i=0;i<N;i++){ //O(n)
            sorted[i]={arr[i],i};
        }
        
        sort(sorted.begin(),sorted.end()); //O(nlogn)
        
        int i=0;
        
        while(i<N){ //O(n)
            int idx=sorted[i].second; 
            if(idx!=-1){
                ans[idx]=rank;
            }
            if(i+1<N && sorted[i].first!=sorted[i+1].first){
                rank++;
            }
            i++;
        }
        return ans;
    }
};
