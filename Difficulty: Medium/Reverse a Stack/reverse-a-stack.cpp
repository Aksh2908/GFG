class Solution {
  private:
    void solve(stack<int>& st, int data, int top){
        if(st.empty()){
            st.push(data);
            return;
        }
        top=st.top();
        st.pop();
        solve(st,data,top);
        st.push(top);
    }
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int data=st.top();
        st.pop();
        reverseStack(st);
        solve(st,data,-1);
    }
};