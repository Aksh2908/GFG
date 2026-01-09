class Solution {
  private:
    void solve(int n,vector<string>& ans, string &temp){
        if(n==0){
            ans.push_back(temp);
            return;
        }
        temp+='0';
        solve(n-1,ans,temp);
        temp.pop_back();
        temp+='1';
        solve(n-1,ans,temp);
        temp.pop_back();
    }
  public:
    vector<string> binstr(int n) {
        // code here
        vector<string> ans;
        string temp="";
        solve(n,ans,temp);
        return ans;
    }
};