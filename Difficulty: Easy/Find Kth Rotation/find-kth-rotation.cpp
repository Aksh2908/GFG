class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int low=0,high=n-1;

        if(n==1) return 0;

        int ans=INT_MAX;
        int idx=-1;

        while(low<=high){
            int mid=(high-low)/2+low;
            if(arr[low]<=arr[mid]){
                if(arr[low]<ans){
                    ans=arr[low];
                    idx=low;
                }
                low=mid+1;
            }
            else{
                if(arr[mid]<ans){
                    ans=arr[mid];
                    idx=mid;
                }
                high=mid-1;
            }
        }

        return idx;
    }
};
