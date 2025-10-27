class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxi=-1;
        int secondMaxi=-1;
        for(auto it:arr){
            if(it>maxi){
                secondMaxi=maxi;
                maxi=max(maxi,it);
            }
            else if(it<maxi && it>secondMaxi){
                secondMaxi=max(secondMaxi,it);
            }
        }
        return secondMaxi;
    }
};