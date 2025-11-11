// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        if(!(*head_ref)) return;
        while((*head_ref) && (*head_ref)->data==x){
            Node* temp=(*head_ref);
            (*head_ref)=(*head_ref)->next;
            delete temp;
        }
        
        Node* temp=(*head_ref);
        if(temp) temp->prev=nullptr;
        
        while(temp){
            Node* del=temp;
            if(temp->data==x){
                if(temp->prev) temp->prev->next=temp->next;
                if(temp->next) temp->next->prev=temp->prev;
                temp=temp->next;
                delete del;
            }
            else{
                temp=temp->next;
            }
        }
    }
};