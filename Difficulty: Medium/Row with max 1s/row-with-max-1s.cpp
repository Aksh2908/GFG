// User function template for C++
class Solution {
  private:
    int firstOccurence(vector<int>& arr, int val, int m){
        int low=0,high=m-1; int ans=m;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        
        int m=arr[0].size();
        int maxCnt=0;
        int maxRow=-1;
        for(int i=0;i<n;i++){
            if(m-firstOccurence(arr[i],1,m)>maxCnt){
                maxCnt=m-firstOccurence(arr[i],1,m);
                maxRow=i;
            }
        }
        return maxRow;
    }
};