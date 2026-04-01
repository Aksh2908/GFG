class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        if(!root) return -1;
        int ceil=-1;
        
        Node* curr=root;
        
        while(curr){
            if(curr->data==x){
                return x;
            }
            if(curr->data>x){
                ceil=curr->data;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        return ceil;
    }
};
