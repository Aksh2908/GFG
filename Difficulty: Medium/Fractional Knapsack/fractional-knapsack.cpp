// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  private:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        double aUnit=(double)a.first/a.second;
        double bUnit=(double)b.first/b.second;
        return aUnit>bUnit;
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<pair<int,int>> ans;
        
        for(int i=0;i<n;i++){
            ans.push_back({val[i],wt[i]});
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
        double maxVal=0;
        for(int i=0;i<n;i++){
            if(capacity-ans[i].second>0){
                maxVal+=ans[i].first;
                capacity-=ans[i].second;
            }
            else{
                double frac=((double)(ans[i].first)/(double)(ans[i].second))*capacity;
                maxVal+=frac;
                break;
            }
        }
        return maxVal;
    }
};
