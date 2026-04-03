/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeValue{
    public:
        int maxVal;
        int minVal;
        int size;
        
    public:
        NodeValue(int minVal,int maxVal, int size){
            this->minVal=minVal;
            this->maxVal=maxVal;
            this->size=size;
        }
};
class Solution {
  public:
    NodeValue solve(Node* root){
        if(!root)
            return NodeValue(INT_MAX,INT_MIN,0);
            
            auto left=solve(root->left);
            auto right=solve(root->right);
            
            if(left.maxVal<root->data && root->data<right.minVal){
                return NodeValue(min(root->data,left.minVal),max(root->data,right.maxVal),left.size+right.size+1);
            }
            
            return NodeValue(INT_MIN,INT_MAX,max(left.size,right.size));
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        return solve(root).size;
    }
};