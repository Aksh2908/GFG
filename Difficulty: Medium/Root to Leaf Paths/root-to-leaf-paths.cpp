/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    bool isLeaf(Node* root){
        return (!root->left && !root->right);
    }
    
    void solve(Node* root, vector<vector<int>>& ans, vector<int>& temp){
        if(!root) return;
        
        temp.push_back(root->data);
        
        if(isLeaf(root)){
            ans.push_back(temp);
        }
        
        
        if(root->left) solve(root->left,ans,temp);
        if(root->right) solve(root->right,ans,temp);
        temp.pop_back();
    }
    
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> temp;
        
        solve(root,ans,temp);
        
        return ans;
    }
};