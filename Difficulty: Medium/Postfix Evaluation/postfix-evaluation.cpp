class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        int n=arr.size();
        stack<long long> st;
        int res=0;
        for(auto it:arr){
            if(it=="+" || it=="-" || it=="*" || it=="/" || it=="^"){
                long long val2=st.top();
                st.pop();
                long long val1=st.top();
                st.pop();
                if(it=="+") res=val1+val2;
                else if(it=="-") res=val1-val2;
                else if(it=="*") res=val1*val2;
                else if(it=="/"){
                    res=floor((long double)val1/val2);
                }
                else res=pow(val1,val2);
                
                st.push(res);
            }
            else{
                st.push(stoll(it));
            }
        }
        return (int)st.top();
    }
};