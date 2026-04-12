/*The structure of Node

struct Node {
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
    Node* find(Node* root, Node* x){
        Node* curr=root;
        Node* succ=nullptr;
        while(curr){
            if(curr->data>x->data){
                succ=curr;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        return succ;
    }
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        if(!root) return -1;
        if(!x) return -1;
        Node* succ=find(root,x);
        if(!succ) return -1;
        return succ->data;
    }
};