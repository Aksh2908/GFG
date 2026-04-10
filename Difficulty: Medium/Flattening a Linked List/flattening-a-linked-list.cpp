/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  private:
    Node* merge(Node* l1, Node* l2){
        Node* dummy= new Node(-1);
        Node* temp=dummy;
        
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
        Node* flattenHead=flatten(root->next);
        return merge(flattenHead,root);
    }
};