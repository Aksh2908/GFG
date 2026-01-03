// User function Template for C++

class Solution {
  private:
    int solve(int r){
        int rem=r%4;
        if(rem==0) return r;
        else if(rem==1) return 1;
        else if(rem==2) return r+1;
        return 0;
    }
  public:
    int findXOR(int l, int r) {
        return solve(r)^solve(l-1);
    }
};