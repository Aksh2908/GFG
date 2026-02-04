class Solution {
  private:
    void solve(Node* root, int x, int &ceil){
        if(!root) return;
        
        if(root->data>=x) ceil=root->data;
        if(root->data>x) solve(root->left,x,ceil);
        if(root->data<x) solve(root->right,x,ceil);
    }
  public:
    int findCeil(Node* root, int x) {
        // code here
        if(!root) return -1;
        
        int ceil=-1;
        
        solve(root,x,ceil);
        
        return ceil;
    }
};
