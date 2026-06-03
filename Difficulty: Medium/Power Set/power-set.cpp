class Solution {
  private:
    void solve(string& s, int idx, int len, vector<string>& ans,string& temp){
        if(idx==len){
            ans.push_back(temp);
            return;
        }
        temp.push_back(s[idx]);
        solve(s,idx+1,len,ans,temp);
        temp.pop_back();
        solve(s,idx+1,len,ans,temp);
    }
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> ans;
        int n=s.length();
        string temp="";
        solve(s,0,n,ans,temp); // O(2^n)
        sort(ans.begin(),ans.end()); //O(nlogn)
        return ans;
    }
};