class Solution {
  private:
    int merge(vector<int>& arr, int low, int mid, int high){
        int left=low,right=mid+1;
        vector<int> ans;
        int cnt=0;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                ans.push_back(arr[left]);
                left++;
            }
            else{
                cnt+=(mid-left+1);
                ans.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            ans.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            ans.push_back(arr[right]);
            right++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=ans[i-low];
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int low, int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid=(low+high)/2;
        cnt+=mergeSort(arr,low,mid);
        cnt+=mergeSort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
        return cnt;
    }
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return mergeSort(arr,0,n-1);
    }
};