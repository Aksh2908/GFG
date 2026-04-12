
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        unordered_map<char,int> mpp;
        
        for(auto it:s){
            mpp[it]++;
        }
        
        for(auto it:s){
            if(mpp[it]==1) return it;
        }
        
        return '$';
    }
};