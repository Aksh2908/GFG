/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        if(!root) return -1;
        
        int floor=-1;
        
        Node* curr=root;
        
        while(curr){
            if(curr->data==x){
                floor=x;
            }
            if(curr->data>x){
                curr=curr->left;
            }
            else{
                floor=curr->data;
                curr=curr->right;
            }
        }
        
        return floor;
    }
};