/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  private:
    Node* merge(Node* left, Node* right){
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        
        Node* l1=left;
        Node* l2=right;
        
        while(l1 && l2){
            if(l1->data<=l2->data){
                temp->bottom=l1;
                l1=l1->bottom;
            }
            else{
                temp->bottom=l2;
                l2=l2->bottom;
            }
            
            temp=temp->bottom;
        }
        
        if(l1){
            temp->bottom=l1;
        }
        if(l2){
            temp->bottom=l2;
        }
        
        return dummy->bottom;
    }
  public:
    Node *flatten(Node *root) {
        // code here
        if(!root || !root->next) return root;
        Node* merged=flatten(root->next);
        return merge(merged,root);
    }
};