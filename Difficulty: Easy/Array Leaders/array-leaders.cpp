

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n=arr.size();
        
        vector<int> ans;
        
        int maxi=arr[n-1];
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
                maxi=arr[i];
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};