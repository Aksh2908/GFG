
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        int parent=n/2-1;
        while(parent>=0){
            int left=2*parent+1;
            int right=2*parent+2;
            if(arr[parent]<arr[left]) return false;
            if(arr[parent]<arr[right]) return false;
            parent--;
        }
        return true;
    }
};