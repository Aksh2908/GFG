/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution { 
  private:
    bool isLeaf(Node* root){
        return (!root->left && !root->right);
    }
    bool solve(Node* root){
        if(!root || isLeaf(root)) return true;
        
        int sum=0;
        if(root->left) sum+=(root->left->data);
        if(root->right) sum+=(root->right->data);
        
        if(sum!=root->data) return false;
        
        bool left=solve(root->left);
        bool right=solve(root->right);
        if(!left || !right) return false;
        return true;
    }
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(!root) return true;
        
        return solve(root);
    }
};