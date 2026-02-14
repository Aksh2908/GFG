/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void dfs(Node* root,vector<int>& bst){
        if(!root) return;
        dfs(root->left,bst);
        bst.push_back(root->data);
        dfs(root->right,bst);
    }
    
    vector<int> merge(vector<int>& bst1, vector<int>& bst2){
        int i=0,j=0;
        vector<int> ans;
        
        while(i<bst1.size() && j<bst2.size()){
            if(bst1[i]<=bst2[j]){
                ans.push_back(bst1[i]);
                i++;
            }
            else{
                ans.push_back(bst2[j]);
                j++;
            }
        }
        
        while(i<bst1.size()){
            ans.push_back(bst1[i]);
            i++;
        }
        
        while(j<bst2.size()){
            ans.push_back(bst2[j]);
            j++;
        }
        
        return ans;
    }
  public:
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> bst1;
        vector<int> bst2;
        
        dfs(root1,bst1);
        dfs(root2,bst2);
        
        return merge(bst1,bst2);
    }
};