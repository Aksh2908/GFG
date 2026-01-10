class Solution {
  private:
    void solve(stack<int>& st, int data, int top){
        if(st.empty()){
            st.push(data);
            return;
        }
        if(st.top()<=data){
            st.push(data);
            return;
        }
        top=st.top();
        st.pop();
        solve(st,data,top);
        st.push(top);
    }
  public:
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int data=st.top();
        st.pop();
        sortStack(st);
        solve(st,data,-1);
    }
};
