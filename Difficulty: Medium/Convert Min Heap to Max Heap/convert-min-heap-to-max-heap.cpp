// User function Template for C++

class Solution {
  private:
    void heapifyDown(vector<int>& arr, int i, int n){
        int parent=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && arr[parent]<arr[left]){
            parent=left;
        }
        if(right<n && arr[parent]<arr[right]){
            parent=right;
        }
        
        if(parent!=i){
            swap(arr[parent],arr[i]);
            heapifyDown(arr,parent,n);
        }
    }
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i=(N/2)-1;i>=0;i--){
            heapifyDown(arr,i,N);
        }
    }
};
