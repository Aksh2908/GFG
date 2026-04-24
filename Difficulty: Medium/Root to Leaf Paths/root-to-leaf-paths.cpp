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
    void solve(Node* root, vector<vector<int>>& ans, vector<int>& temp){
        if(!root) return;
        temp.push_back(root->data);
        
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
        else{
            solve(root->left,ans,temp);
            solve(root->right,ans,temp);
        }
        temp.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        if(!root) return {};
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root,ans,temp);
        return ans;
    }
};