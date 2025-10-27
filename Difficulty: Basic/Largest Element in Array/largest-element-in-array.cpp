class Solution {
  private:
    int solve(vector<int>& arr){
        int n=arr.size();
        int maxi=INT_MIN;
        for(auto it:arr){
            if(it>maxi){
                maxi=max(maxi,it);
            }
        }
        return maxi;
    }
  public:
    int largest(vector<int> &arr) {
        return solve(arr);
    }
};
