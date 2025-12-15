// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int x=n;
        int arm=0;
        while(x!=0){
            int b=x%10;
            arm+=pow(b,3);
            x=x/10;
        }
        if(n==arm) return 1;
        return 0;
    }
};