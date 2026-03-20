/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
    void addLeft(Node* root, vector<int>& res){
        Node* curr=root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    
    void addLeaf(Node* root, vector<int>& res){
        if(!root) return;
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        addLeaf(root->left,res);
        addLeaf(root->right,res);
    }
    
    void addRight(Node* root, vector<int>& res){
        vector<int> temp;
        
        Node* curr=root->right;
        
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeft(root,res);
        addLeaf(root,res);
        addRight(root,res);
        return res;
    }
};