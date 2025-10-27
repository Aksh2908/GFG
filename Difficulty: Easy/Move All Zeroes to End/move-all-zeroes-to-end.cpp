class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=1;
        while(i<n && j<n){
            if(!arr[i] && arr[j]){
                swap(arr[i],arr[j]);
            }
            else if(!arr[i] && !arr[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    }
};