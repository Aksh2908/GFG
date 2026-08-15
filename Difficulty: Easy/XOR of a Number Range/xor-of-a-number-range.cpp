class Solution {
  private:
    int x(int n){
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
        return n;
    }
  public:
    int findXOR(int l, int r) {
        // code here
        return x(r)^x(l-1);
    }
};