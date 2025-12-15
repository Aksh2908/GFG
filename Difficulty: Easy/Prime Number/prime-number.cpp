class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n<=1) return 0;
        int flag=0;
        for(int i=2;i<n;i++){
            if(!(n%i)){
                flag=1;
                break;
            }
        }
        if(flag) return 0;
        return 1;
    }
};
