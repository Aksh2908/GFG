// User function template for C++

class Solution {
  private:
    static int comp(const void* a, const void* b) {
        int x = *(const int*)a;
        int y = *(const int*)b;
        return x - y; 
    }

  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        typedef pair<int,int> pp;
        
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        
        qsort(arr,n,sizeof(int),comp);
        
        for(int i=0;i<n;i++){
            if(abs(i-pq.top().second)>k) return "No";
            pq.pop();
        }
        return "Yes";
    }
};