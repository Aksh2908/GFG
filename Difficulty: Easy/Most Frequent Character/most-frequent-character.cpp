class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        map<char,int> mpp;
        
        for(auto it:s){
            mpp[it]++;
        }
        
        int maxi=INT_MIN;
        char maxChar;
        
        for(auto it:mpp){
            if(maxi<it.second){
                maxChar=it.first;
                maxi=it.second;
            }
        }
        
        return maxChar;
    }
};