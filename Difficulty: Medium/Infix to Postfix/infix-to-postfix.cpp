class Solution {
  private:
    int prec(char c){
        if(c=='^') return 3;
        if(c=='/' || c=='*') return 2;
        if(c=='+' || c=='-') return 1;
        return -1;
    }
  public:
    string infixToPostfix(string& s) {
        string ans="";
        int n=s.length();
        stack<char> st;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                if(isalnum(s[i])){
                   ans+=s[i]; 
                }
                else{
                    while(!st.empty() && ((prec(s[i])<prec(st.top())) || (prec(s[i])==prec(st.top()) && s[i]!='^'))){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
